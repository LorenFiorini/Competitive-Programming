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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << endl;
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << endl;
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second
//
ifstream input("full-input.txt");
ofstream output("full-OUTPUT.txt");

vint get_string() {
	string s;
	input >> s;	
	int n = len(s);
	vint v(n);
	rep (i, 0, n) {
		v[i] = s[i] - 'A';
	}
	showv(v,n);
	return v;
}

vvi get_adj() {
	// Adjencency matrix
	int numEdges;
	input >> numEdges;
	
	vvi adj(26, vint (26, INF));
	rep (i,0,26) {
		adj[i][i] = 0;
	}
	
	rep (i, 0 , numEdges) {
		string edge;
		input >> edge;
		adj[edge[0] - 'A'][edge[1] - 'A'] = 1;
	}
	return adj;
}

void floyd_warshall(vvi &v) {
	
	rep (k, 0, 26) {
		rep (i, 0, 26) {
			rep (j, 0, 26) {
				if (v[i][k] < INF && v[k][j] < INF)
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	
	//showvv(v, 26, 26);
}




void solve (){
	int ans = INF;	
	vint s = get_string();
	vvi v = get_adj();
	int n = s.size();
	
	floyd_warshall(v);
	
	rep (j, 0, 26) 
	{
		int sum = 0;
		rep (i, 0, n) {
			if (v[s[i]][j] == INF) {
				sum = INF;
				break;
			}
			sum += v[s[i]][j];
		}
		ans = min(ans, sum);
	}
	
	
	// Write to file
	if (ans >= INF) 
		ans = -1;
	output << ans << "\n";
}

int main () 
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini
