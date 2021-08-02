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
/*
int bi (int low, int high, int p) {
	while (high > low) {
		int mid = (low + high) / 2;
		if () {
			high = mid - 1;
		}
		else if (p % mid == 0) {
			return mid;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}*/




void solve () {
	int ans;
	ll n,m,p;
	cin >> n >> m >> p;
	//int x = min(m,n); int y = max(m,n);
	if (p > m *n) {
		cout << "NO\n";
		return;
	}
	if (m > n) {
		int tmp = m;
		m = n;
		n = tmp;
	}
	RREP (i, 1+m, 1) {
		if (i / 2  * n > p) {
			i /= 2;
			i++;
			continue;
		}
		if (p % i == 0) {
			if (p / i <= n) {
				cout << "YES\n";
				return;
			}
		}
		if (i * n < p) break; 
	}
	cout << "NO\n";
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


