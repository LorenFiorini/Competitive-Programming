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
	int ans = 0;
	int n;
	cin >> n;
	map<int, int> m;
	map<int, int>:: iterator it;
	REP (i, 0, n) {
		int num;
		cin >> num;
		it = m.find(num);
		if (it == m.end()) {
			m.insert({ num, 1});
		} else {
			it->second++;
		}
	}
	vector<int> v;
	FOREACH(it, m) {
		v.push_back(it->second);
	}
	sort(v.begin(), v.end(), greater<int>());
	int sz = v.size();
	int sum = 0;
	REP  (i, 1,sz) sum+=v[i];
	
	if (sz == 1) {
		cout << n << "\n";
		return; 
	} else if (v[0] <= sum) {
		ans = n % 2;
		cout << ans << "\n";
		return; 
	}
	/*
	int gr = 0;
	int re = 1;
	while (1) {
		int tmp = v[gr] - v[re];
		if (tmp > 0) {
			v[gr] = tmp; // diferencia;
			re++;
		} else {
			v[gr] = 0;
			gr = re;
			re++;
		}
		if (re>=sz) break;
		
	}
	REP (i,0,sz) ans+= v[i];*/
	ans = v[0] - sum;
	
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


