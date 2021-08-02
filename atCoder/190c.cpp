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
	int ans = -1;
	int n, m, k;
	cin >> n >> m;
	vector<int> dish(n, 0);
	vector<int> a(m);
	vector<int> b(m);
	REP (i, 0, m) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}
	cin >> k;
	vector<int> c(k);
	vector<int> d(k);
	REP (i, 0, k) {
		cin >> c[i] >> d[i];
		c[i]--;
		d[i]--;
		dish[c[i]]++;
	}
	REP (i, -1, k) 
	{
		int sum = 0;
		if (i >= 0) {
			dish[c[i]]--;
			dish[d[i]]++;
		}
		REP (j, 0 , m) {
			if (dish[a[j]] > 0 && dish[b[j]] > 0) sum++;
		}
		if (sum > ans) {
			ans = sum;
		} else {
			dish[c[i]]++;
			dish[d[i]]--;	
		}
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

