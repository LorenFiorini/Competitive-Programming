#include<bits/stdc++.h>
using namespace std;

int main() {
	int n ,m;
	cin >> n >> m;
	bool ok = 1;
	
	vector<vector<char>> v(n, vector<char> (m));
	for (vector<char> &vec : v) {
		for (char &a : vec) {
			cin >> a;
			if (a != 'W' && a != 'G' && a != 'B' ) ok = 0;
		}
	}
	
	string s = "#Black&White";
	if (not ok) s = "#Color";
	
	cout << s << endl;
}

