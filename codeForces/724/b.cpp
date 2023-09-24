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
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

void next(vint &cmp) {
	int i = len(cmp) - 1;
	cmp[i]++;
	while (cmp[i] >= 27) {
		if (i - 1 > 0) {
			cmp[i] = 1;
			cmp[i-1]++;
			i--;
		} else {
			cmp[i]++;
			if (cmp[i] >= 27){
				cmp[i] = 1;
				cmp.pb(1);
			}
			break;
		}
	}
}

bool check(vint &v, vint &cmp) {
	int m = len(v) + 1 - len(cmp);
	rep (i, 0, m) 
	{
		int cnt = 0;
		rep (j, 0, len(cmp)) 
		{
			if (v[i + j] == cmp[j]) {
				cnt++;
			} 
		}
		if (cnt == len(cmp)) {
			return false;
		}
	}
	
	return true;
}

void showalpha(vint &cmp, string alpha) {
	rep (i, 0, len(cmp)) {
		cout << alpha[cmp[i]];
	}
	cout << endl;
}
void solve () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vint v(n);
	string alpha = "`abcdefghijklmnopqrstuvwxyz";
	rep (i, 0, n) {
		int num = s[i] - '`';
		v[i] = num;
	}
	
	vint cmp(1, 1);
	while (1) {
		if (check(v, cmp)) {
			break;
		}
		//showalpha(cmp, alpha);
		//showv(cmp, len(cmp));
		next(cmp);
	}
	//show(len(alpha));
	//showv(v, n);
	showalpha(cmp, alpha);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
