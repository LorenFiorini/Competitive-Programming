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


ll b, c, ans = 0;
set<ll> st;
set<ll> :: iterator it;

ll tree(ll num, ll cash, int ant) {
	if (cash <= 0) {
		return 1;
	} 
	
	if (ant == 0) {
		ans++;
		tree(num * (-1), cash - 1, 1);
	}
	//it = st.find(num - 1);
	ans++;
	tree(num -1, cash - 2, 0);
	return 1;
}


void solve () {
	cin >> b >> c;
	tree(b, c, 0);
	//ans = st.size();
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int t; cin >> t;
	//while (t--) 
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

