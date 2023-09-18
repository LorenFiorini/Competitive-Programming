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
	int a, b, w;
	cin >> a >> b >> w;
	w *= 1000;
	
	int mn = w / b;
	//if (w % b > 0) mn++;
	int mx =  w / a;
	
	if (w % a > mx * (b - a)) {
		cout << "UNSATISFIABLE\n";
		return;
	} else if (w % b > 0){
		mn++;
		double tmp = (double) w / (double) mn;
		if (!(tmp >= (double) a && tmp <= (double) b) ) {
			cout << "UNSATISFIABLE\n";
			return;
		}
	}
	cout << mn << " " << mx << "\n";
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


