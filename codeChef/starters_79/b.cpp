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
#include <iomanip>
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
#define por(i, a, b, in) for (ll i = a; i < (b); i += in)
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

vll pr;
ll N;
void sieve()
{
	ll n = 33000;
    //bool prime[n+1];
    //memset(prime, true, sizeof(prime));
 	vint prime(n+1, 1);
    for (ll p=2; p <=n; p++)
    {
        if (prime[p] == true)
        {
        	pr.pb((ll)p);
            for (ll i = p; i <= n; i += p) {
				prime[i] = false;
            }
        }
    }
    N = len(pr);
	//showv(pr);
}

ll find_div(ll x) {
	for (auto div: pr) {
		if ((x % div) == 0) {
			return div;
		}
	}
	ll ans = 1;
	return ans;
}

void solve () {
	ll ans = 0;
	ll x, y;
	cin >> x >> y;
	
	while (x % 2) {
		ll num = find_div(x);
		x += num;
		ans++;
	}
	ll dif = y - x;
	ans += (dif / 2) + (dif % 2);

	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
