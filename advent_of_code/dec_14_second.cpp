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
//
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


//int M = 52 + 4, N = 156 + 20;
// 17 -> +1 for padding
//int M = 501, N = 1001;
int N = 501, M = 1001;

void print_matrix(vvi &v);
vvi input();

int dfs(vvi &v, int r, int c, int &sum) {
	if (c < 0 || c == M) return 0;
	if (r == 170 || v[r][c] != 0) return 1;
	//showp(r, c);

	if (dfs(v, r + 1, c, sum) &&
		dfs(v, r + 1, c - 1, sum) &&
		dfs(v, r + 1, c + 1, sum)) {
		v[r][c] = 5;
		sum++;
		return 1;
	}

	return 0;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans = 0;
	vvi v = input();

	dfs(v, 0, 500, ans);

	show(ans);
	print_matrix(v);

	return 0;
}

void print_matrix(vvi &v) {
	rep (i, 0, N) {
		rep (j, 0, M) {
			if (v[i][j]) cout << v[i][j] << " ";
			else cout <<  "- ";
		}
		cout << endl;
	}
}

vvi input () {
	vvi v(N, vint(M, 0));

	int n = 151;
	rep (i, 0, n) {
		int m, x, y;
		cin >> m;
		rep (j, 0, m) {
			int X = 0, Y = 0;
			cin >> Y >> X;
			//X -= 13; X += 20; // top
			//Y -= 483; Y += 2; // padding
			
			if (j == 0) {
				x = X;
				y = Y;
			}

			if (x == X) {
				int sta = min(y, Y);
				int fin = max(y, Y) +1;
				rep (k, sta, fin) {
					v[x][k] = 1;
				}
			}
			if (y == Y) {
				int sta = min(x, X);
				int fin = max(x, X) +1;
				rep (k, sta, fin) {
					v[k][y] = 1;
				}
			}
			x = X;
			y = Y;
		}
	}

	return v;
}
// Lorenzo Fiorini
// 248191 answer is too high.
// 27811 for row 172
// 27155 for row 170
