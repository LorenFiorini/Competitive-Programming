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


vector<int> ans(100, 0);


int help(vector<int> v, int left, int right) {
	if (left == right) {
		//ns[left] = 0;
		return -1;
	}
	int p = left;
	int mx = 0;
	REP (i, left, right) {
		if (v[i] > mx) {
			mx = v[i];
			p = i;
		}
	}
	ans[p] = max(help(v, left, p), help(v, p+1, right)) + 1;
	return (int) ans[p];
}




void solve () {
	int n, p;
	cin >> n;
	vector<int> v(n);
	REP (i, 0, n) {
		cin >> v[i];
		if (v[i] == n) p = i;
	}
	ans[p] = max(help(v, 0, p), help(v, p+1, n)) + 1;
	
	REP (i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << "\n";
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

