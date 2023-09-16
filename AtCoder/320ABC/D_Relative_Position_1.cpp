#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> read_input(int n, int m) {
	vector<vector<vector<int>>> v(n);
	for (int i = 0; i < m; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		a--; b--;
		v[a].push_back({b, x, y});
	}
	return v;
}

void solve () {
	vector<int> ans;
	int n, m;
	cin >> n >> m;
	// {++, --, +-, -+}
	// vector<vector<int>> pos(n, vector<int>(2));
	// Index[person] is a map {x,y} -> count_of_occurences
	vector<vector<vector<int>>> v = read_input(n, m);
	// vector<map< pair<int,int>, int>> pos(n);

	// pos[0][{0, 0}]++;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < v[i].size(); j++) {
	// 		int b = v[i][j][0];
	// 		int x = v[i][j][1];
	// 		int y = v[i][j][2];
	// 		pos[b][{x, y}]++;
	// 	}
	// }
	vector<pair<int, int>> pos(n);
	pos[0] = {0, 0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int b = v[i][j][0];
			int x = v[i][j][1];
			int y = v[i][j][2];
			if (pos[b].first == -1 && pos[b].second == -1) {
				pos[b] = {pos[i].first + x, pos[i].second + y};
			} else {
				if (pos[b].first != pos[i].first + x || pos[b].second != pos[i].second + y) {
					cout << "undecidable" << endl;
					return;
				}
			}
		}
	}
	
	for (auto p: pos) {
		cout << p.first << " " << p.second << endl;
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