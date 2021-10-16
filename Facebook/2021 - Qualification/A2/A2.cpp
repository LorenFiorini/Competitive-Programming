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
ifstream input("sample-input.txt");
ofstream output("sample-OUTPUT.txt");

int n;

mpii bfs(vvi &adj, int start) {
	vint dist(n, INF);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		
		for (int to : adj[from])
		{
			if (dist[to] == INF) {
				dist[to] = dist[from] + 1;
				q.push(to);
			}
		}
	}
	
	
	// Set of <node, distance>
	mpii st;
	rep (i, 0, n) {
		st[i] = dist[i];
	}	
	return st;
}



void solve (){
	int ans = INF;
	// Input from string to vint
	string s;
	input >> s;
	n = len(s);
	vint v(n);
	rep (i, 0, n) {
		v[i] = s[i] - 'A';
	}
	
	// Adjencency matrix
	int numEdges;
	input >> numEdges;
	vvi adj(26);
	rep (i, 0 , numEdges) {
		string edge;
		input >> edge;
		adj[edge[0] - 'A'].pb(edge[1] - 'A');
	}
	
	// reachable node <from, <to, dist>>
	map<int, mpii> mp;
	
	rep (i, 0, n) {
		if (mp.find(v[i]) == mp.end()) {
			mp[v[i]] = bfs(adj, v[i]);
		}
	}
	
	
	/*
	each (iter, mp) 
	{
		int to = iter->ff;
		int sum = 0;
		* dont go through the map, but through the vint
		each (it, mp) 
		{	
			auto f = it->ss.find(to);
			if (f->ss == INF) {
				sum = INF;
				break;
			} else {
				sum += (int) f->ss;
			}
		}
		ans = min(ans, sum);
	}*/
	
	
	
	if (ans == INF) ans = -1;
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
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
