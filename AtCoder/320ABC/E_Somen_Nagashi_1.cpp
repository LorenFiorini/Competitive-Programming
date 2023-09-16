#include<bits/stdc++.h>
using namespace std;

void solve () {
	long long n, m;
	cin >> n >> m;
	// time = 0; pos = 0..n-1
	vector<long long> ans(n, 0);
	// {time, pos}
	priority_queue<pair<long long, long long>,
		vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	
	for (long long i = 0; i < n; i++) pq.push({0, i});

	for (long long i = 0; i < m; i++) {
		long long t, w, s;
		cin >> t >> w >> s;
		
		if (pq.top().first <= t) {
			pair<long long, long long> p = pq.top(); pq.pop();
			ans[p.second] += w;
			pq.push({t + s, p.second});
		}
		for (auto a : ans) cout << a << " "; cout << endl;
	}
	
	for (auto a : ans) cout << a << endl;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */

/*
Problem Statement
There are 
N people gathered for an event called Flowing Noodles. The people are lined up in a row, numbered 
1 to 
N in order from front to back.

During the event, the following occurrence happens 
M times:

At time 
T 
i
​
 , a quantity 
W 
i
​
  of noodles is flown down. The person at the front of the row gets all of it (if no one is in the row, no one gets it). That person then steps out of the row and returns to their original position in the row at time 
T 
i
​
 +S 
i
​
 .
A person who returns to the row at time 
X is considered to be in the row at time 
X.

After all the 
M occurrences, report the total amount of noodles each person has got.

Constraints
1≤N≤2×10 
5
 
1≤M≤2×10 
5
 
0<T 
1
​
 <…<T 
M
​
 ≤10 
9
 
1≤S 
i
​
 ≤10 
9
 
1≤W 
i
​
 ≤10 
9
 
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
M
T 
1
​
  
W 
1
​
  
S 
1
​
 
⋮
T 
M
​
  
W 
M
​
  
S 
M
​
 
Output
Print 
N lines. The 
i-th line should contain the amount of noodles person 
i has got.
*/
