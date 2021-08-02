#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
typedef int ll;
typedef pair<ll, ll> pii;
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


ll sumprefix(vll v, ll maxi) {
	ll sum = 0;
	rep (i, 0, nn) {
		sum += min(maxi, v[i]);
	}
	return sum;
}


void input () {
	ll n , k , l;
	// inputs
	cin >> n >> k >> l;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	sort(allg(v));
	ll tot = k * l;
	
	// START
	ll ind = n; 
	while (v[ind-1] + k < ind) ind--;
	if (v[ind-1] + k == ind) ind++;
	
	
	// END
	ll mn = 1;
	while (v[mn-1] > mn) mn++;
	if (v[mn-1] < mn) mn--;
	ll ans = mn;
	if (l == 0 || k == 0){
		show(ans);
		return;
	}
	//
	ll lst = 0;
	rrep(j, ind, mn) {
		ll i = j+1;
		ll ocu = sumprefix(v, i);
		ll need = (i * i) - ocu;
		if (need <= tot) {
			ans = i;
			break;
		}
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();	
	return 0;
}

