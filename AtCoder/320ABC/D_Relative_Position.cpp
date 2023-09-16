#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<vector<ll>>> read_input(ll n, ll m) {
	vector<vector<vector<ll>>> v(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, x, y;
		cin >> a >> b >> x >> y;
		a--; b--;
		v[a].push_back({b, x, y});
		v[b].push_back({a, -x, -y});
	}
	return v;
}

void solve () {
	vector<ll> ans;
	ll n, m;
	cin >> n >> m;
	vector<vector<vector<ll>>> v = read_input(n, m);
	vector<vector<ll>> pos(n);
	pos[0].push_back(0);
	pos[0].push_back(0);

	queue<ll> q;
	q.push(0);
	// for (ll i = 0; i < n; i++) {
	while (!q.empty()) {
		ll i = q.front();
		q.pop();
		ll len = v[i].size();
		for (ll j = 0; j < len; j++) {
			ll b = v[i][j][0];
			ll x = v[i][j][1];
			ll y = v[i][j][2];
			if (pos[b].size() < 2) {
				// pos[b] = {pos[i][0] + x, pos[i][1] + y};
				pos[b].push_back(pos[i][0] + x);
				pos[b].push_back(pos[i][1] + y);
				q.push(b);
			} else if (pos[b].size() == 2) {
				if ((pos[b][0] != pos[i][0] + x) || (pos[b][1] != pos[i][1] + y)) {
					pos[b].push_back(0);
				}
			}


		}
	}
	
	for (auto p: pos) {
		if (p.size() == 2) {
			cout << p[0] << " " << p[1] << endl;
		} else {
			cout << "undecidable" << endl;
		}
	}
	
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
N people numbered 
1 to 
N on a coordinate plane.
Person 
1 is at the origin.

You are given 
M pieces of information in the following form:

From person 
A 
i
​
 's perspective, person 
B 
i
​
  is 
X 
i
​
  units away in the positive 
x-direction and 
Y 
i
​
  units away in the positive 
y-direction.
Determine the coordinates of each person. If the coordinates of a person cannot be uniquely determined, report that fact.

Constraints
1≤N≤2×10 
5
 
0≤M≤2×10 
5
 
1≤A 
i
​
 ,B 
i
​
 ≤N
A 
i
​
 

=B 
i
​
 
−10 
9
 ≤X 
i
​
 ,Y 
i
​
 ≤10 
9
 
All input values are integers.
The given information is consistent.
Input
The input is given from Standard Input in the following format:

N 
M
A 
1
​
  
B 
1
​
  
X 
1
​
  
Y 
1
​
 
⋮
A 
M
​
  
B 
M
​
  
X 
M
​
  
Y 
M
​
 
Output
Print 
N lines.
If the coordinates of person 
i cannot be uniquely determined, the 
i-th line should contain undecidable.
If they can be uniquely determined as 
(s 
i
​
 ,t 
i
​
 ), the 
i-th line should contain 
s 
i
​
  and 
t 
i
​
  in this order, separated by a space.


*/