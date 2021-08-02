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

//  GLOBAL VARIABLES
map <int , pii> M;
map <int , pii> O;
map <int , pii> :: iterator COOR;
set< pii > imp;
set< pii > :: iterator IMPO;
vector<seti> comb;
seti :: iterator sit;
set<string> boards;

void set_maze(vstr &lines, vvi &maze, pii &start, vvi &vis);
void add (int num, vint &need);
void DFS(vvi &maze, pii start, vint need, vvi &vis);
void get_coor(int idx, pii &xy);
bool MOO(seti &st);

int a[4] = {-1, 0, 1, 0};
int b[4] = {0, 1, 0, -1};
int n;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	vstr lines(n);
	rep (i, 0, n) cin >> lines[i];
		
	
	vvi vis (n, vint (n, 0));
	vvi maze(n, vint (n));
	pii start;
	set_maze(lines, maze, start, vis);
	
	vint need;
	seti emp;
	comb.pb(emp);
	//showvv(vis, n, n);
		
	DFS(maze, start, need, vis);	
	
	/*
	rep(i,0,len(comb)) {
		showset(sit, comb[i]);
	}*/
	
	/*
	rep (i, 0, len(comb)) {
		MOO(comb[i]);
	}
	*/
	
	show(len(boards));
	
	return 0;
}


void set_maze(vstr &lines, vvi &maze, pii &start, vvi &vis) {	
	int idx = 1;
	vpii vec;
	rep (i, 0, n){
		for (int j = 0; j < (3 * n); j += 3) {
			if (lines[i][j] == '#') {
				maze[i][j / 3] = -1;
				vis[i][j / 3] = 1;
			}
			else if (lines[i][j] == '.') 
				maze[i][j / 3] = 0;
			else if (lines[i][j] == 'B') {
				maze[i][j / 3] = 0;
				start = mk(i, j / 3);
			} else {
				maze[i][j / 3] = idx;
				int r = lines[i][j+1] - '0';
				int c = lines[i][j+2] - '0';
				pii coor = mk(r, c);
				// map M and O 
				if (lines[i][j] == 'M') {
					M[idx] = coor;
				} else if (lines[i][j] == 'O') {
					O[idx] = coor;					
				}
				vec.pb(coor);
				idx++;
			}
		}
	}
	
	int sz = len(vec);
	rep (i, 0, sz - 1) {
		rep (j, i + 1, sz) {
			if (vec[i] == vec[j]) 
			{
				pii par = mk(i + 1, j + 1);
				imp.insert(par);
			}
		}
	}
}

//---------------------------------------------------------------------


void add (int num, vint &need) {
	int N = len(comb);/*
	if (len(need) == 0) {
		seti firs;
		firs.insert(num);
		comb.pb(firs);
	}*/
	rep (i, 0, N) {
		bool ok = true;
		rep (j, 0, len(need)) {
			if (notin(comb[i], need[j])) ok = false;
		}
		if (!ok) continue;
		
		bool ok2 = true;
		seti newset;
		newset.insert(num);
		each (sit, comb[i]) {
			pii pp = mk(min(num, *sit), max(num, *sit));
			if ( ! notin(imp, pp)) ok2 = false;
			newset.insert(*sit);
		}
		if (!ok2) continue;
		
		if (!MOO(newset)) {
			comb.pb(newset);
		}		
	}
}




void DFS(vvi &maze, pii start, vint need, vvi &vis) {
	int r = start.ff;
	int c = start.ss;
	if (vis[r][c] == 1) return;
	
	//showp(r, c);
	vis[r][c] = 1; 
	
	int num = maze[r][c];
	bool continuo = true;
	
	if (num > 0) {
		bool agrego = true;
		seti newset;
		rep (i, 0, len(need)) {
			newset.insert(need[i]);
			pii pp = mk(min(num, need[i]), max(num, need[i]));
			if ( ! notin(imp, pp)) agrego = false;
		}
		
		
		if (agrego) {
			newset.insert(num);
			if (MOO(newset)) {
				continuo = false;
			} 
			add(num, need);
			need.pb(num);
		}
	}
	if (!continuo) return;
	
	rep (i, 0, 4) {
		pii pos = mk(r + a[i], c + b[i]);
		DFS(maze, pos, need, vis);
	}
}

//----------------------------------------------------------------------

void get_coor(int idx, pii &xy) {
	if ( ! notin(O, idx)) {
		COOR = O.find(idx);
		xy.ff = (-1);
		xy.ss = (-1);
		xy.ff *= COOR->ss.ff;
		xy.ss *= COOR->ss.ss;
	} else if( ! notin(M, idx)){
		COOR = M.find(idx);
		xy.ff = (1);
		xy.ss = (1);
		xy.ff *= COOR->ss.ff;
		xy.ss *= COOR->ss.ss;
	}
	return;
}


bool MOO(seti &st) {
	bool valido = false;
	vstr tt(3, "---");
	each(sit, st)
	{
		int idx = *sit;
		pii coor;
		get_coor(idx, coor);
	
		char ch;
		if (coor.ff < 0 || coor.ss < 0) {
			coor.ff *= (-1);
			coor.ss *= (-1);
			ch = 'O';
		} else {
			ch = 'M';
		}
		coor.ff -= 1;
		coor.ss -= 1;
	
		tt[coor.ff][coor.ss] = ch;		
	}
	
	string moo = "MOO";
	string oom = "OOM";
	
	bool kk[6] = {1,1,1,1,1,1};
	rep (i, 0, 3) {
		if (tt[0][i] != moo[i]) kk[0] = false;
		if (tt[0][i] != oom[i]) kk[1] = false;
		if (tt[1][i] != moo[i]) kk[2] = false;
		if (tt[1][i] != oom[i]) kk[3] = false;
		if (tt[2][i] != moo[i]) kk[4] = false;
		if (tt[2][i] != oom[i]) kk[5] = false;
	}
	rep (i, 0, 6) if (kk[i] == 1) valido = true;
	
	bool ok[6] = {1,1,1,1,1,1};
	rep (i, 0, 3) {
		if (tt[i][0] != moo[i]) ok[0] = false;
		if (tt[i][0] != oom[i]) ok[1] = false;
		if (tt[i][1] != moo[i]) ok[2] = false;
		if (tt[i][1] != oom[i]) ok[3] = false;
		if (tt[i][2] != moo[i]) ok[4] = false;
		if (tt[i][2] != oom[i]) ok[5] = false;
	}
	rep (i, 0, 6) if (ok[i] == 1) valido = true;
	
	bool ook[4] = {1,1,1,1};
	rep (i, 0, 3) {
		if (tt[i][i] != moo[i]) ook[0] = false;
		if (tt[i][i] != oom[i]) ook[1] = false;
		if (tt[i][2 - i] != moo[i]) ook[2] = false;
		if (tt[i][2 - i] != oom[i]) ook[3] = false;
	}
	rep (i, 0, 4) if (ook[i] == 1) valido = true;
	
	if (valido) {
		string s = "";
		rep(i, 0, 3) {
			s += tt[i];
		}
		//show("*******");
		if (notin(boards, s)) {
			boards.insert(s);
		}
	}
	
	return valido;
}





