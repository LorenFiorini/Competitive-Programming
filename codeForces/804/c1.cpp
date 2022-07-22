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
/*
0 - 2 3 4 original
4 0 3 2 1 V
0 1 1 1 5 mex
1 2 3 4 5 choose
        1 
if (mp[num] > 1) ans += (num-1)! 
40321
40231
01115
	===> 2

0==> 1
	
0 1 2 3
1 2 3 4 mex
	===> 1

1 2 4 0 5 3		x F a a  F
0 0 0 3 3 6 	F a a F n+1
3! * 2


MEX
000336
1xx0x3 One is also fixed!!!
124053
125043

let p=3=Mi, n=6
 =>	p-1 mustbe
	12x, 1x2, ... for x = p+1 ... n
===> 3! * 2
12x
1x2
21x
2x1
x12
x21
=> 4 = 2! * 2

1 3 7 2 5 0 6 4
0 0 0 0 0 4 4 8 
1 x x x x 0 x 4
=>	4! = 24
	4! * 3
1. 123 must be 
	123

*/

ll mod = 1000000007;
ll n;
void MEX(vint &v, vint &a) {
	vector<bool> van(n, 0);
	int j = 0;
	rep(i, 0, n) {
		van[v[i]] = 1;
		while (van[j]) j++;
		a[i] = j;
	}
}

void solve () {
	ll ans = 1;
	
	cin >> n;
	vint v(n);
	rep(i, 0, n) cin >> v[i];

	vint a(n);
	vint b(n);
	MEX(v, a);
	showv(a, n); show("");

	sort(all(v));
	do {
		MEX(v, b);
		if (a == b) {
			showv(v, n);
		}
	} while (next_permutation(all(v)));

}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
/*
4 0 3 2 1 	length
0 1 0 0 0 	1
 1 1 0 0 	2
  1 1 0 	3
   1 4 		4
    5 		5

 4  0  3  2  1
				0 1 0 0 0 		1
				 x  0  x  x  x
				1 1 0 0 -		2
				>1  0 >1  x  x
 1 	1  0  -  -					3
>1  0 >1 >1 >0

 1  4  -  -  -					4
>1  0 >1 >1 >0
<5  0 <4 <4 <4
 3  1  2  2  3  
3-223


sum == 11
pro == 2^2 * 3^2 = 36

-1 =>	20112
choose	11211 == 2  

40321
40231

124053
000100	1
00110	2
0111 	3
311		4
31 		5
6 		6

 1  2  4  0  5  3
 0  0  0  3  3  6 
          1  2  1 choose
 0  1  2  3  4  5

0 -> 3 =>	 1 [3,3] len =	1 	fix=1
1 -> 0 =>	>1 [0,3]		4 	fix=2 	(4-2)!
2 -> 1 =>	>2 [0,3]		4 
3 -> 5 => 	>3 [0,5]		6 	fix=4 or all
4 -> 2 => 	>4 [0,5]		6
5 -> 4 => 	>5 [0,5]		6

*/