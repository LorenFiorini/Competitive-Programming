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
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
#define sho(x) cout << x << " ";
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
void showvv(vvi vv, int n, int m) {
	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << vv[i][j] << "	";
		} 
		cout << "\n";
	}
}
bool winning(map<pii, char> &need);
void st(vstr &lines, pii &start);
void DFS(pii start, map<pii, char> need, vvi &vis, vstr maze);
//bool MOO(vstr &tt);
void last_count() ;

map<pii, char> :: iterator it;
vector<vector< pair<pii, char>> >vek;

int a[4] = {-1, 0, 1, 0};
int b[4] = {0, 3, 0, -3};
int n, answer = 0;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	vstr lines(n);
	rep (i, 0, n) cin >> lines[i];
		
	
	vvi vis (n, vint (3 * n, 0));
	pii start;
	st(lines, start);
	map<pii, char> need;
	
		
	DFS(start, need, vis, lines);	
	
	last_count();
	
	show(answer);
	
	return 0;
}

//---------------------------------------------------------------------

void st(vstr &lines, pii &start){
	rep (i, 0, n) por (j, 0, 3 * n, 3) {
		if (lines[i][j] == 'B') {
			start = mk(i, j);
			return;
		}
	}
}



//---------------------------------------------------------------------

bool winning(map<pii, char> &need) {
	if (len(need) < 3) return false;
	vstr tt(3, "---");
	
	each (it, need) {
		int r = it->ff.ff;
		int c = it->ff.ss;
		tt[r][c] = it->ss;
	}
	
	string moo = "MOO";
	string oom = "OOM";
	bool res = false;
	
	bool kk[6] = {1,1,1,1,1,1};
	rep (i, 0, 3) {
		if (tt[0][i] != moo[i]) kk[0] = false;
		if (tt[0][i] != oom[i]) kk[1] = false;
		if (tt[1][i] != moo[i]) kk[2] = false;
		if (tt[1][i] != oom[i]) kk[3] = false;
		if (tt[2][i] != moo[i]) kk[4] = false;
		if (tt[2][i] != oom[i]) kk[5] = false;
	}
	rep (i, 0, 6) if (kk[i] == 1) res = true;
	
	bool ok[6] = {1,1,1,1,1,1};
	rep (i, 0, 3) {
		if (tt[i][0] != moo[i]) ok[0] = false;
		if (tt[i][0] != oom[i]) ok[1] = false;
		if (tt[i][1] != moo[i]) ok[2] = false;
		if (tt[i][1] != oom[i]) ok[3] = false;
		if (tt[i][2] != moo[i]) ok[4] = false;
		if (tt[i][2] != oom[i]) ok[5] = false;
	}
	rep (i, 0, 6) if (ok[i] == 1) res = true;
	
	bool ook[4] = {1,1,1,1};
	rep (i, 0, 3) {
		if (tt[i][i] != moo[i]) ook[0] = false;
		if (tt[i][i] != oom[i]) ook[1] = false;
		if (tt[i][2 - i] != moo[i]) ook[2] = false;
		if (tt[i][2 - i] != oom[i]) ook[3] = false;
	}
	rep (i, 0, 4) if (ook[i] == 1) res = true;
	
	if (res) answer++;
	return res;
}

void DFS(pii start, map<pii, char> need, vvi &vis, vstr maze) {
	int r = start.ff;
	int c = start.ss;
	if (vis[r][c] == 1) return;
	vis[r][c] = 1;
	
	char ch = maze[r][c];
	//showp(r, c/3);
	
	if (ch == '#') return;
	else if (ch == 'M' || ch == 'O') {
		int row = maze[r][c+1] - '0'; row--;
		int col = maze[r][c+2] - '0'; col--;
		pii coor = mk(row, col);
		it = need.find(coor);
		if (it == need.end()){
			need.insert(mk(coor, ch));
			if (winning(need)){
				return;
			} else {
				vector<pair<pii, char>> vvv;
				each(it, need) {
					pair<pii, char> tmp;
					tmp.ff.ff = it->ff.ff;
					tmp.ff.ss = it->ff.ss;
					tmp.ss = it->ss;
					vvv.pb(tmp);
				}
				vek.pb(vvv);
			}
		}	
	}
	
	
	rep (i, 0, 4) {
		pii pos = mk(r + a[i], c + b[i]);
		DFS(pos, need, vis, maze);
	}
}

void last_count() {
	int N = len(vek);
	//show(N);
	rep (fi, 0, N) {
		rep(se, 0, N) {
			if (fi == se) continue;
			map<pii, char> tmp;
			rep (i, 0, len(vek[fi])) {
				pii pp = vek[fi][i].ff;
				char ch = vek[fi][i].ss;
				it = tmp.find(pp);
				if (it == tmp.end())
					tmp.insert(mk(pp, ch));
			}
						
			rep (i, 0, len(vek[se])) {
				pii pp = vek[se][i].ff;
				char ch = vek[se][i].ss;
				it = tmp.find(pp);
				if (it == tmp.end())
					tmp.insert(mk(pp, ch));
			}/*
			each(it, tmp) {
				showp(it->ff.ff, it->ff.ss);
				show(it->ss);
			}*/
			
			vstr tt(3, "---");
			
			each (it, tmp) {
				int r = it->ff.ff;
				int c = it->ff.ss;
				tt[r][c] = it->ss;
			}
			
			string moo = "MOO";
			string oom = "OOM";
			bool res = false;
			
			bool kk[6] = {1,1,1,1,1,1};
			rep (i, 0, 3) {
				if (tt[0][i] != moo[i]) kk[0] = false;
				if (tt[0][i] != oom[i]) kk[1] = false;
				if (tt[1][i] != moo[i]) kk[2] = false;
				if (tt[1][i] != oom[i]) kk[3] = false;
				if (tt[2][i] != moo[i]) kk[4] = false;
				if (tt[2][i] != oom[i]) kk[5] = false;
			}
			rep (i, 0, 6) if (kk[i] == 1) res = true;
			
			bool ok[6] = {1,1,1,1,1,1};
			rep (i, 0, 3) {
				if (tt[i][0] != moo[i]) ok[0] = false;
				if (tt[i][0] != oom[i]) ok[1] = false;
				if (tt[i][1] != moo[i]) ok[2] = false;
				if (tt[i][1] != oom[i]) ok[3] = false;
				if (tt[i][2] != moo[i]) ok[4] = false;
				if (tt[i][2] != oom[i]) ok[5] = false;
			}
			rep (i, 0, 6) if (ok[i] == 1) res = true;
			
			bool ook[4] = {1,1,1,1};
			rep (i, 0, 3) {
				if (tt[i][i] != moo[i]) ook[0] = false;
				if (tt[i][i] != oom[i]) ook[1] = false;
				if (tt[i][2 - i] != moo[i]) ook[2] = false;
				if (tt[i][2 - i] != oom[i]) ook[3] = false;
			}
			rep (i, 0, 4) if (ook[i] == 1) res = true;
			
			if (res) answer++;
		}
	}
}
