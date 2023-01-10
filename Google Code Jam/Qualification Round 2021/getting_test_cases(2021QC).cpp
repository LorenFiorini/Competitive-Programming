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
	cout << n << "\n";
	REP (i, 0, n) {
		cout << v[i] << " ";
	}
	cout << "\n";	
}

void solve () {
	int ans = 0;
	int n = 4;
	vector<int> v(n);
	REP (i,0,n) v[i] = i+1;
	while (next_permutation(all(v))) show(v);
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
/*
 * 
 * 24
4
1 2 4 3 
4
1 3 2 4 
4
1 3 4 2 
4
1 4 2 3 
4
1 4 3 2 
4
2 1 3 4 
4
2 1 4 3 
4
2 3 1 4 
4
2 3 4 1 
4
2 4 1 3 
4
2 4 3 1 
4
3 1 2 4 
4
3 1 4 2 
4
3 2 1 4 
4
3 2 4 1 
4
3 4 1 2 
4
3 4 2 1 
4
4 1 2 3 
4
4 1 3 2 
4
4 2 1 3 
4
4 2 3 1 
4
4 3 1 2 
4
4 3 2 1 

 */

