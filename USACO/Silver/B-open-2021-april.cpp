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

ll table[6][3] = {
	{0,1,3}, 
	{0,2,5}, 
	{0,4,6}, 
	{1,2,4}, 
	{1,5,6}, 
	{2,3,6}, 
};

void set_values(vll &v, ll row) {
	ll x = v[table[row][0]];
	ll y = v[table[row][1]];
	ll z = v[table[row][2]];
	if ((!x && !y) || (!x && !z) || (!z && !y)) return;
	if (!x) {
		v[table[row][0]] = z - y;
	} else if (!y) {
		v[table[row][1]] = z - x;
	} else if (!z) {
		v[table[row][2]] = x + y;
	} 
	return;
}

bool valid_abc(vll &v) {
	rep (i, 0, 7) if (v[i] < 1) return false;
	
	rep (row, 0, 6) {
		ll x = v[table[row][0]];
		ll y = v[table[row][1]];
		ll z = v[table[row][2]];
		if (x + y != z) return false;
	}
	return true;
}

void add(const vll &vec, set<string> &st) {
	ll n = 7;
	vll v(n);
	
	rep (i, 0, 7) {
		v[i] = vec[i];
		if (v[i] <= 0) v[i] = 0;
	}
	
	rep (i, 0, n-1) {
		set_values(v, i);
	}
	if (valid_abc(v)) {
		sort(v.begin(), v.begin() + 3); 
		
		string str = to_string(v[0]);
		str += "-";
		str += to_string(v[1]);
		str += "-";
		str += to_string(v[2]);
		
		if (notin(st, str)){
			st.insert(str);
		}
		
	}	
	return;
	
}


void input () {
	ll n;
	cin >> n;
	vll v(7);
	rep (i, 0, 7) {
		if (i < n) cin >> v[i];
		else v[i] = -i;
	}
	
	set<string> st;
	
	sort(all(v));
	do {
		add(v, st);
	} while (next_permutation(all(v)));
	
	int ans = len(st);
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) input();	
	return 0;
}
