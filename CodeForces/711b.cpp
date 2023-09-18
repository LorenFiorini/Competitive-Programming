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
	int n, w;
	cin >> n >> w;
	list<int> lis;
	list<int>::iterator it = lis.begin();
	REP (i, 0, n) {
		int num;
		cin >> num;
		lis.insert(it, num);
	}
	lis.sort();
	lis.reverse();
	
	int sp = w;
	int ans = 1;
	while (!lis.empty()) {
		if (sp < lis.back()) {
			sp = w;
			ans++;
		}
		for (it = lis.begin(); it != lis.end(); it++) {
			int num = *it;
			if (num <= sp) {
				sp -= num;
				it = lis.erase(it);
				it--;
			} else if (sp == 0){
				sp = w;
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
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

