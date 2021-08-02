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
	int ans = 1;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int p1, pl;
	bool fi = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			if (!fi) {
				fi = true;
				p1 = i;
			}
			pl = i;
		}
	}
	if (p1 == pl) {
		cout << "1\n";
		return;
	}
	int i = p1;
	while (i < pl) {
		int tmp = k;
		while (1) {
			if (s[i+tmp] == '*') {
				ans++;
				i += tmp;
				break;
			} else {
				tmp--;
			}
			
		}
		
	}
	
	
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



