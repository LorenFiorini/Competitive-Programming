#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (ll i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;


ll n, k, l;

ll sumprefix(vll v, ll maxi, ll nn) {
	ll sum = 0;
	rep (i, 0, nn) {
		sum += min(maxi, v[i]);
	}
	return sum;
}

bool check(ll idx, vll v) {
	ll ocu = sumprefix(v, idx, idx);
	ll need = idx * idx - ocu;
	if (need <= k * l) return true;
	return false;
}

void input () {
	ll ans = 0;
	vll v(n);	
	rep (i, 0, n) cin >> v[i];
	sort(allg(v));
	priority_queue<ll> q;	
	rrep(i, n, 0) {
		// altura maxima a v[i]
		ll alt = min(v[0] + k, v[i] + k);
		// papers
		ll lar = i + 1;
		// maximo indice
		ll idx = min(alt, lar);
		
		q.push(idx);
	}	
	while (!q.empty()) {
		ll x = q.top();
		if (x<=ans) break;
		if (check(x, v)) {
			ans = max(ans, x);
		}
		q.pop();
	}
	show(ans);
	return;
}

void solve () {
	cin >> n >> k >> l;
	if (n <= 100) {
		input();
		return;
	}
	ll ans = 0;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	sort(allg(v));
	
	ll ind = n; 
	while (v[ind-1] + k < ind) ind--;
	
	ll mn = 1;
	while (v[mn-1] > mn) mn++;
	if (v[mn-1] < mn) mn--;
	ans = mn - 1;
	
	if (l == 0 || k == 0){
		show(ans);
		return;
	}
	
	vll sum(n);
	rep (i, 0, n) {
		sum[i] = v[i];
		if (i > 0) sum[i] += sum[i - 1];
	}
	//showv(sum,n);
	
	// max extra spaces
	ll limit = l * k;
	vll :: iterator low;
	
	rep (side, mn-1, ind + 1) {
		// index of last element (v[j] > side) maybe >=
		low = lower_bound(all(v), side, greater<ll> ());
		ll j = low - v.begin() - 1;
		
		// AREA already covered
		ll covered = sum[side - 1] - sum[j] + side * (j + 1);
		ll area = side * side;
		
		
		if (area - covered <= limit)	
			ans = max(ans, side);
	}
	
	show(ans);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}
