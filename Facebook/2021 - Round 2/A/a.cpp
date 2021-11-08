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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second
//
ifstream input("valid-input.txt");
ofstream output("valid-output.txt");

int n, m;

int rep_round(vvi &v, vint &s) {
	int ans = 0;
	mpii mp;
	rep(i, 0, m) mp[s[i]]++;
	/*
	mpii st;
	mpii fir;
	rep(i,0,m) st[s[i]]++;
	rep(j, 0, m) fir[v[0][j]]++;
	
	each(it, fir) {
		auto fin = st.find(it->ff);
		if (fin != st.end()) {
			mp[it->ff] = ;
		}
	}*/
	int cool = 0;
	
	rep (i, 0, n) {
		mpii nxt;
		rep (j, 0, m) {
			nxt[v[i][j]]++;
		}
		int sum = 0;
		each(it, nxt) {
			auto fi = mp.find(it->first);
			if (fi != mp.end()) {
				sum += min(fi->ss, it->ss);
			}
		}
		
		if (i==0) cool = sum;	
		
		ans += sum;
		mp.swap(nxt);
	}
	
	ans += m - cool;
	return ans;
}

void solve (){
	int ans = 0;
	input >> n >> m;
	vint s(m);
	rep (i, 0, m) input >> s[i];
	
	vvi v(n, vint (m));
	rep (i, 0, n) {
		rep (j, 0, m) {
			input >> v[i][j];
		}
	}
	
	int rep = rep_round(v, s);
	show(rep);
	
	ans = max(m*n - rep, 0);
	show(ans);
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		cout << "Case #" << CASE << endl;
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini