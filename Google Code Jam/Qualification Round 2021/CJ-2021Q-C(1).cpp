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

int n;

void show (vector<int> v) {
	REP (i, 0, n) 
		cout << v[i] << " ";
	cout << "\n";	
}

int f(vector<int> v) {
	int ans = 0;
	REP (i, 0, n - 1) {
		int le = i, ri = i;
		REP (j, i, n) {
			if (v[j] == i+1) {
				ri = j;
				break;
			}
		}
		ans += ri - le + 1;
		reverse(v.begin() + le, v.begin() + ri+1); 
	}
	return ans;
}


void solve () {
	int c;
	cin >> n >> c; 
	int mx = (n * (n+1)) / 2 - 1;
	if (c < n - 1 || c > mx) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<int> v(n);
	REP (i,0,n) v[i] = i + 1;
	while (f(v) != c){
		next_permutation(v.begin(), v.end());
	}
	
	show(v);
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

