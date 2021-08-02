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
	int ans;
	int k;
	cin >> k;
	string s; cin >> s;
	string t; cin >> t;
	int suma = 0;
	int sumb = 0;
	vector<int> cards(9, k);
	vector <int> ao(5, 0);
	REP (i, 0, 4) {
		int a = s[i] - '0';
		suma += a;
		int b = t[i] - '0';
		sumb += b;
		cards[a - 1]--;
		cards[b - 1]--;
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

