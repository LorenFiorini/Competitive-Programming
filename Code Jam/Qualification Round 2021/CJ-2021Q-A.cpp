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

void show (vector<int> v) {
	int n = v.size();
	REP (i, 0, n) {
		cout << v[i] << " ";
	}
	cout << "\n";	
}

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vector<int> l(n); // maybe
	REP (i, 0, n) cin >> l[i];
	//ans = n - 1;
	
	REP (i, 0, n - 1) {
		int le, ri;
		le = i;
		ri = i; // nem tudom miert
		// buscar ri en el vector gonna be equal to i+1
		REP (j, i, n) {
			if (l[j] == i+1) {
				ri = j;
				break;
			}
		}
		ans += ri - le + 1;
		reverse(l.begin() + le, l.begin() + ri+1); // no incluye second pointer [ , )
		//show(l);
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}

