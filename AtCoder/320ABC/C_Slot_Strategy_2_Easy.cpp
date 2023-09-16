#include<bits/stdc++.h>
using namespace std;

void solve () {
	int ans = 1e9;
	int m, n = 3;
	cin >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i] = s[i] + s[i] + s[i];
	}
	
	for (char dig = '0'; dig <= '9'; dig++) {
		vector<vector<int>> pos(3);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3*m; ++j) {
				if (s[i][j] == dig) {
					pos[i].push_back(j);
				}
			}
		}
		if (pos[0].size() < 3 || pos[1].size() < 3 || pos[2].size() < 3) continue;

		int mx = 0;
		int mn = 1e9;
		set<int> st;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				st.insert(pos[j][i]);
				mx = max(mx, pos[j][i]);
				mn = min(mn, pos[j][i]);
				if (st.size() == 3) {
					ans = min(ans, mx );
					break;
				}
			}
			if (st.size() == 3) break;
		}
	}
	
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
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
This problem is an easier version of Problem G.

There is a slot machine with three reels.
The arrangement of symbols on the 
i-th reel is represented by the string 
S 
i
​
 . Here, 
S 
i
​
  is a string of length 
M consisting of digits.

Each reel has a corresponding button. For each non-negative integer 
t, Takahashi can either choose and press one button or do nothing exactly 
t seconds after the reels start spinning.
If he presses the button corresponding to the 
i-th reel exactly 
t seconds after the reels start spinning, the 
i-th reel will stop and display the 
((tmodM)+1)-th character of 
S 
i
​
 .
Here, 
tmodM denotes the remainder when 
t is divided by 
M.

Takahashi wants to stop all the reels so that all the displayed characters are the same.
Find the minimum possible number of seconds from the start of the spin until all the reels are stopped so that his goal is achieved.
If this is impossible, report that fact.

Constraints
1≤M≤100
M is an integer.
S 
i
​
  is a string of length 
M consisting of digits.
Input
The input is given from Standard Input in the following format:

M
S 
1
​
 
S 
2
​
 
S 
3
​
 
Output
If it is impossible to stop all the reels so that all the displayed characters are the same, print -1.
Otherwise, print the minimum possible number of seconds from the start of the spin until such a state is achieved.
*/
