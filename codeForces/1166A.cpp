#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define vint vector<ll> 
#define vstr vector<string> 
#define show(x) cout << x << "\n";
#define showv(v, n) rep (i,0,n) {cout << v[i] << " ";} cout << "\n";
#define mk(a, b) make_pair(a, b)
#define f first
#define s second
#define pb(a) push_back(a)
#define len(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define mpii map<ll,ll> 



ll n;
ll choose(ll a) {
	if (a < 2) return (ll) 0;
	
	ll ans = 1;
	rep (i, 3, a+1) {
		ans *= i;
	}
	ll div = 1;
	rep (i, 1, (a - 2) + 1) {
		div *= i;
	}
	return (ll) (ans / div);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vstr v(n);
	rep (i, 0, n) cin >> v[i];
	
	mpii mp;
	mpii::iterator it;
	rep (i, 0, n) {
		ll num = v[i][0] - 'a';
		it = mp.find(num);
		if (it == mp.end()) {
			mp[num] = 1;
		} else {
			it->s++;
		}
	}
	
	ll ans = 0;
	
	for (it = mp.begin(); it != mp.end(); it++) {
		ll a = it->s / 2;
		ll b = a;
		if (it->s % 2) b++;
		//show(it->s);
		
		ans += choose(a);
		ans += choose(b);
	}
	
	show(ans);
	return 0;
}
