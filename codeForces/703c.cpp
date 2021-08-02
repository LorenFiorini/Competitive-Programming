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

int ans;
void help (int l, int r, int ant) {
	if (l == r) {
		ans = l;
		return;
	}
	int p;	
	cout << "? " << l << " "<< r << endl;
	fflush(stdout);
	cin >> p;
	if (p != ant) return;
	if (ans == 0) help(l, p - 1, p);
	if (ans == 0) help(p + 1, r, p);
	return;
}



void solve () {
	ans = 0;
	int n;
	cin >> n;
	int l = 1, r = n;
	int ant;
	cout << "? " << l << " "<< r << endl;
	fflush(stdout);
	cin >> ant;
	help(l, ant, ant);
	help(ant, r, ant);
	cout << "! "<< ans << endl;
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
