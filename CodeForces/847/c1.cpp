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
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

int n;

void showP(set<vint> &pos) {
	//show("---");
	for (auto arr: pos) {
		showv(arr); 
		cout << "";
	}
	cout << endl;
}

set<vint> possibilities(vint &vec) {
	// number not in 
	// push_back
	// swap until first position
	int num;
	seti st(all(vec));

	rep(i, 1, n + 1) {
		if (st.find(i) == st.end()) {
			num = i;
			break;
		}
	}

	set<vint> ans;
	vint tmp(all(vec));
	tmp.push_back(num);
	ans.insert(tmp);

	for (int i = n-1; i > 0; i--) {
		swap(tmp[i], tmp[i-1]);
		ans.insert(tmp);
	}
	return ans;
}



void solve () {
	vint ans;
	cin >> n;
	vvi per(n, vint(n-1));
	rep (i, 0, n) {
		rep (j, 0, n - 1) {
			cin >> per[i][j];
		}
	}

	set<vint> pos = possibilities(per[0]);
	
	
	
	rep (i, 1, n) {
		set<vint> posi = possibilities(per[i]);
		set<vint> nxt;
		vint tmp;

		////
		//show("---");
		//showP(posi);
		//showP(pos);
		each(it, pos) {
			tmp = *it;
			//next_permutation(all(tmp));
			if (posi.find(tmp) != posi.end()) {
				nxt.insert(tmp);
			}
		}
		//show(len(nxt));
		/*
		if (len(nxt) == 1) {
			ans = *nxt.begin();
			while (i) {
				prev_permutation(all(ans));
				i--;
			}
			break;
		}*/
		if (len(nxt) == 1) {
			ans = *nxt.begin();
			break;
		}
		pos.swap(nxt);
	}
	
	// for (auto arr: pos) {showv(arr); cout << "";}

	showv(ans);
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
