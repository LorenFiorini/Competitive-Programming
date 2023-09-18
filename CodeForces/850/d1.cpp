#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
// My Favorite Macros
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
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << " ";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

// i, n, w
// IT WORKS !!!
// Damn it, I was so close on this one

void fun(string row, int &a, int &b, int &a1, int &b1) {
	vint vec(3, 0);
	rep (j, 0, 3) {
		if (row[j] == 'w') {
			vec[2]++;
		} else if (row[j] == 'i') {
			vec[1]++;
		} else if (row[j] == 'n') {
			vec[0]++;
		}
	}
	rep (i, 0, 3) {
		if (vec[i] == 3) {
			a = (1 << i);
			a1 = (1 << i);
			b = (1 << ((i + 1) % 3));
			b1 = (1 << ((i + 2) % 3));
		}
		if (vec[i] == 2) {
			a = (1 << i);
			rep (j, 0, 3) {
				if (vec[j] == 0) {
					b = (1 << j);
				}
			}
		}

	}
}

char get(int num) {
	if (num & 1) return 'n';
	if (num & 2) return 'i';
	return 'w';
}

void solve () {
	int n, m = 3;
	cin >> n;
	vstr v(n);
	rep (i, 0, n) cin >> v[i];
	vector<vector<pair<int, char>>> ans;

	// map id -> {extra_letters, needed_letters}
	// {extra_letters, needed_letters} -> vector<int> ids
	map< pii , vint> mp;

	rep (i, 0, n) {
		//int extra, needed
		int a = 0, a1 = 0;
		int b = 0, b1 = 0;
		fun(v[i], a, b, a1, b1);

		rep (QQ, 0, 4) {

			if (a || b) {
				pii p = {b, a};
				if (mp[p].size() > 0) {
					int id = mp[p].back();
					mp[p].pop_back();

					vector<pair<int, char>> tmp;
					tmp.pb(make_pair(id, get(b)));
					tmp.pb(make_pair(i + 1, get(a)));
					ans.pb(tmp);
				} else {
					pii p = {a, b};
					mp[p].push_back(i + 1);
				}
			}
			swap(a, a1);
			swap(b, b1);
			a1 = b1 = 0;
		}
	}


	// Triplets
	// {extra_letters, needed_letters} -> ids
	// Needed -> {Extra, id}
	map<int, vector<pii>> mapa;

	while (mp.size() > 0) {
		//each (it, mp) {
		//	cout << get(it->ff.ff) << " " <<  get(it->ff.ss) << "\n";
		//	showv(it->ss);
		//}
		//cout << "***\n";

		each(it, mp) {
			int extra = it->first.first;	// id
			int needed = it->first.ss;		// id
			//cout << get(extra) << " " <<  get(needed) << "\n";
			while (it->ss.size() > 0) {
				int id = it->ss.back();
				it->ss.pop_back();
				//show(id);


				if (mapa[extra].size() > 0) {
					pii par = mapa[extra].back();
					mapa[extra].pop_back();
					
					vector<pair<int, char>> tmp;
					tmp.pb(mk(id, get(extra)));
					tmp.pb(mk(par.ss, get(par.ff)));
					ans.pb(tmp);

					if (needed != par.ff)
					mapa[needed].pb(make_pair(par.ff, id));
				} else {
					mapa[needed].pb(make_pair(extra, id));
				}
				/*
				MAPA
				T = 1
					// w -> {n, 1}
					// -
					// -
				T = 2
					// w -> {n, 1}
					// n -> {i, 3}
					// -
				T = 3
					// ----------
					// n -> {i, 3}
					// i -> {n, 1}

				*/
			}
		}
		mp.clear();
		if (mapa.size() > 0) {
			auto it = mapa.begin();
			while (it != mapa.end() && it->ss.size() == 0) {
				//cout << it->ff << " " <<  get(it->ff) << "---";
				//cout << get(it->ss.ff) << " " <<  get(it->ff) << "\n";
				//show()
				it++;
			}

			if (it == mapa.end()) break;
			//cout << "dsa";

			int ne = it->ff;
			for (auto par: it->ss) {

				int ex = par.ff;
				int id = par.ss;
				mp[make_pair(ex, ne)].pb(id);
			}
			mapa.erase(it);
		}

		//each (it, mp) {
		//	cout << get(it->ff.ff) << " " <<  get(it->ff.ss) << "\n";
		//	showv(it->ss);
		//}
	}



	int N = len(ans);
	show(N);
	rep (i, 0, N) {
		rep (j, 0, 2) showp(ans[i][j].ff, ans[i][j].ss);
		cout << endl;
	}
	//show("____");
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
