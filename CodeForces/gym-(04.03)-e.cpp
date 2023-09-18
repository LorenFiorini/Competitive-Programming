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
typedef vector<pii> vii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(i, vv, n, m) rep(i, 0, n) {showv(j, vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


void solve () {
	int ans = 0;
	int n, m;
	cin >> m >> n;
	vint notes(n);
	rep (i, 0, n) cin >> notes[i];
	int num = 4 * m;
	//mseti st;
	//mseti :: iterator it;
	mpii mp;
	mpii :: iterator it;
	rep (i, 1, num+1) {
		mp.insert(mk(i, 0));
	}
	//vint v;
	rep (i, 0, n) {
		int tmp = notes[i];
		while (tmp <= num) {
			//st.insert(tmp);
			//v.pb(tmp);
			it = mp.find(tmp);
			it -> second++;
			tmp += notes[i];
		}
	}
	/*
	int sz = v.size();
	sort(all(v));
	rep (i, 0, sz) {
		rep (j, 0, sz) {
			if (i == j) {
				continue;
			}
			int tmp = v[i] + v[j];
			if (tmp > num) break;
			if (notin(mp, tmp)) {
				mp.insert(mk, 1);
			} else {
				it = mp.find(tmp);
				it -> second++;
			}
		}
	}*/
	it = mp.find(num);
	if (it != mp.end()) {
		ans += it->second;
	}
	int tam = mp.size();
	int i = 0;
	each (it, mp) {
		if (i >= tam / 2) break;
		int sum = min(it->ss, mp.at(num - it->ff));		
		ans += sum;		
		i++;
	}
	
	
	show(ans);
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

