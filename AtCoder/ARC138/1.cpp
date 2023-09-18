#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
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
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

seti st;
ll n;
ll sz = 18;

void load(vint &v, int num, int sz) {
	for (int i = sz-1; i >= 0; i--) {
		v[i] = num%2;
		num /= 2;
	}
}

int dif(int a, int b) {
	int ans = 0;
	int num = a ^ b;
	while (num > 0) {
		ans += num % 2;
		num /= 2;
	}
	return ans;
}

void solve () {
	cin >> n;
	vint v(sz);
	
	int N = 1 << n;
	rep(i, 0, N) {
		load(v, i, sz);
		showv(v, sz);
	}
	
	mpii mp;
	rep(i, 0, N) {
		
		rep(j, 0, N) {
			int num = dif(i, j);
			mp[num]++;
			if (num == 1) cout << "* "; else
			if (num == n-1) cout << "+ "; else
			//cout << num << " ";
			cout << "  ";
		}
		
		cout << "\n";
	}
	showmap(it, mp);
	
	/*
	rep(from, 0, 1 << n) {
		show("*****");
		load(v, from, sz);
		show(from);
		//showv(v, sz);
		show("-----");
		
		rep(k, 0, 1 << n) {
			//if (st.find(k) != st.end()) show("------");
			show(dif(from, k));
			
			//load(v, k, sz);
			//showv(v, sz);
		}
	}*/
	show("Yes");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	rep(i, 1, 19) st.insert(1 << i);
	showset(it, st);
	solve();
	
	return 0;
}

// Lorenzo Fiorini
