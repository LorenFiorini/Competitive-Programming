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
	ll ans = 0;
	int A, B, K;
	cin >> A >> B >> K;
	vector<int> boys(A, 0);
	vector<int> girls(B);
	vector<pair<int, int>> edges(K);
	//vector<int> a(K);
	//vector<int> b(K);
	REP (i, 0, K) 
		cin >> edges[i].first;
	for (auto &[x, y] : edges)
		cin >> y;
	// Any way works
	for (auto &[x, y] : edges) 
	{
		x--; //to make it 0-index instead
		y--;
		boys[x]++;
		girls[y]++;
	}
	for (auto &[x, y] : edges) 
	{
		ans += K - boys[x] - girls[y] + 1;
	}
	cout << ans / 2 << "\n";
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
