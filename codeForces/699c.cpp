#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	map<int, int> mp;
	map<int, int>::iterator it;
	REP (i, 0, n) cin >> a[i];
	REP (i, 0, n) {
		cin >> b[i];
		if (a[i] == b[i]) continue;
		it = mp.find(b[i]);
		if (it == mp.end()) {
			mp.insert(pair<int, vector<int>> (b[i], vector<int> (i + 1)));
		} else {
			it->second.push_back(i+1);
		}
	}
	
	vector<int> ans(m);
	int replace = -1;
	REP (i, 0, m) {
		int tmp;
		cin >> tmp;
		it = mp.find(tmp);
		if (it != mp.end()) {
			if (it->second.size() != 0) {
				ans = it->second.back();
				if (i == m-1) replace = it->second.back();
				it->second.pop_back();
			}
		}
		ans[i] = -1;
	}
	if (replace != -1) {
		FOREACH (it, mp) {
			if (it >= 0)
		}
	} else
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name
