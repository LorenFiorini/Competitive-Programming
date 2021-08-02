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
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(i, vv, n, m) rep(i, 0, n) {showv(j, vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;



void solve () {
	int ans = 0;
	// INPUT
	int n, k;
	cin >> k >> n;
	
	vstr nam(n);
	map<string, int> mp;
	map<string, int> :: iterator mit;
	rep (i, 0, n) {
		string str;
		cin >> str;
		nam[i] = str;
		mp[str] = 0;
	}
	
	// TASKS
	rep (papers, 0, k)
	{
		vstr res(n);
		vii pos(n);
		rep (i, 0, n) {
			cin >> res[i];
			pos[i].ff = i;
			pos[i].ss = i;
			if (i && res[i - 1] < res[i]) {
				pos[i].ff = pos[i-1].ff;
			}
		}
		rrep (i, n - 1, 0) {
			pos[i+1].ss = max(i+1, pos[i+1].ss);
			if (pos[i].ff == pos[i+1].ff) {
				pos[i].ss = pos[i+1].ss;
			}
		}
		rep (i, 0, n) {
			mp[res[i]] += pos[i].ff + pos[i].ss;
		}
	}
	/*
	showv(nam, n);
	showmap(mit, mp);*/
	
	rep (i, 0, n) {
		rep (j, 0, n) 
		{
			if (i == j) cout << 'B';
			else if (mp.at(nam[i]) > mp.at(nam[j])) cout << '1';
			else if (mp.at(nam[i]) < mp.at(nam[j])) cout << '0';
			else if (mp.at(nam[i]) == mp.at(nam[j])) cout << '?';
		}
		show("");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

