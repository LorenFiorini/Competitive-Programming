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
	//int ans;
	int n, x;
	cin >> n >> x;
	REP (i, 0, n){
		int tmp;
		cin >> tmp;
		if (tmp != x) cout << tmp << " ";
	}
	
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}


