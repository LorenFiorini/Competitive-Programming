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

void show (map<int, int> mp) {
	map<int, int>::iterator it;
	FOREACH(it, mp){
		cout << it->first << " " << it->second << "\n";
	}
}

void solve () {
	int n, w;
	cin >> n >> w;
	map<int, int> mp;
	map<int, int>:: iterator it;
	map<int, int>:: reverse_iterator rit;
	REP (i, 0, n) {
		int tmp;
		cin >> tmp;
		it = mp.find(tmp);
		if (it == mp.end()) {
			mp.insert({tmp, 1});
		} else {
			it->second++;
		}
	}
	//show(mp);
	int sp = w;
	int ans = 1;
	while (!mp.empty()) {
		it = mp.begin();
		if (sp < it->first) {
			sp = w;
			ans++;
		}
		for (rit = mp.rbegin(); rit != mp.rend(); rit++) {
			if (rit->first <= sp) {
				sp -= rit->first;
				rit->second--;
				if (rit->second == 0) {
					it = mp.find(rit->first);
					mp.erase(it);
					break;
				}
				break;
			} else if (sp == 0) {
				sp = w;
				ans++;
				break;
			}
			//cout << sp << "\n";
		}
		//cout << "\n" << ans << "\n\n";
	}
	if (sp == w) ans--;
	
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


