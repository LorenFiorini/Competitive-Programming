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
	int ans = 0;
	int n;
	cin >> n;
	int a = 1e5 + 1;
	int b = 1e5 + 1;
	int bb = b;
	int p = 0;
	int pb = 0;
	REP (i, 0, n) {
		int tmp, bbb;
		cin >> tmp >> bbb;
		if (tmp < a) {
			a = tmp;
			p = i;
		} else if (tmp == a) p = -1;
		if (bbb <= b) {
			bb = b;
			b = bbb;
			pb = i;
		}
	}
	if (p == pb) {
		ans = min(a + b, max(a, bb));
	} else {
		ans = max(a, b);
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name


