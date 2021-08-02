#include <bits/stdc++.h>
using namespace std;

#define rep (i, a, b) for (int i = a: i < b; i++)
#define ll long long
#define vint vector<int>
#define show(x) cout << x << "\n";
#define all(v) v.begin(), v.end()
#define mk make_pair()
#define pb push_back



int main () {
	string s;
	string t;
	getline(cin, s);
	getline(cin, t);
	
	
	map<char, int> mps;
	map<char, int> mpt;
	map<char, int>::iterator it;
	
	int n = s.size();
	int m = t.size();
	
	for (int i = 0; i < n; i++) {
		it = mps.find(s[i]);
		if (it == mps.end()) {
			mps[s[i]] = 1;
		} else {
			it->second++;
		}
	}
	
	for (int i = 0; i < m; i++) {
		it = mpt.find(t[i]);
		if (it == mpt.end()) {
			mpt[t[i]] = 1;
		} else {
			it->second++;
		}
	}
	
	for (it = mps.begin(); it != mps.end(); it++) {
		int cant = mpt[it->first];
		if ((int)it->second != cant) {
			cout << it->first;
		}
	}
	cout << "\n";
	
	return 0;
}
