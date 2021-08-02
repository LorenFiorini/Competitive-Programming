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
	string ans;
	int a, b,c;
	cin >> a>>b>>c;
	if (c == 1){
		int tmp = a;
		a = b;
		b = tmp;
	}
	a--;
	while (a > 0 && b > 0) 
	{
		b--;
		if (b== 0) break;
		a--;
	}
	
	if (c == 0) 
	{
		if (a == 0){
			ans = "Aoki";			
		} else {
			ans = "Takahashi";
		}
	} else {
		if (a == 0){
			ans = "Takahashi";
		} else {
			ans = "Aoki";
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
