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
ifstream input("full-input.txt");
ofstream output("full-output.txt");

int R, C, K;
int ans;

int sum_row(vvi &v, int row) {
	int an = 0;
	rep (j, 0, C) {
		an += v[row][j];
	}
	return an;
}

void up_row(vvi &v, vint &up) {
	// desde K row 
	rep (i, K, R){
		// sumo K row ppriemro
		int extra = 0;
		int cur = 0;
		rep (j, 0, C) {
			up[j] += v[i][j];
			if (K < up[j]) {
				extra += 1;//up[j] - K;
			} else if (i+1 < R){
				cur += v[i+1][j];
			}
		}
		
		int tmp = cur + extra + (i-K + 1);
		//if (tmp > ans ) break;
		ans = min(ans, tmp);
		cout << cur << "\t"  << extra << "\t"  << (i-K + 1) << "\n";
	}
}

void down_row(vvi &v, vint &down) {
	// desde K row 
	for (int i = K; i >= 0; i--){
		// sumo K row ppriemro
		int extra = 0;
		int cur = 0;
		rep (j, 0, C) {
			down[j] += v[i][j];
			if ((R-(K+1)) < down[j]) {
				extra += 1;//down[j] - (R-(K+1));
			} else if (i-1 >= 0){
				cur += v[i-1][j];
			}
		}
		
		int tmp = cur + extra + (K-i + 1);
		//if (tmp > ans ) break;
		ans = min(ans, tmp);
		cout << cur << "\t"  << extra << "\t"  << (K-i + 1) << "\n";
	}
}

vint get_up(vvi &v) {
	vint up(C, 0);
	rep (i, 0, K-1) {
		rep (j, 0, C) {
			up[j] += v[i][j];
		}
	}
	return up;
}

vint get_down(vvi &v) {
	vint d(C, 0);
	rep (i, K, R) {
		rep (j, 0, C) {
			d[j] += v[i][j];
		}
	}
	return d;
}

void solve (){
	// Input
	input >> R >> C >> K;
	vvi v(R, vint(C, 0));
	rep (i, 0, R) {
		string r;
		input >> r;
		rep (j ,0, C) {
			if (r[j] == 'X') v[i][j] = true;
		}
	}
	
	// take all cars from K line
	ans = sum_row(v, K-1);
	cout << ans << endl;
	
	vint up = get_up(v);
	vint down = get_down(v);
	showv(up, C);
	showv(down, C);
	cout << endl;
	
	K--;
	if (K > 0) up_row(v, up);
	cout << endl;
	if (K+1 < R) down_row(v, down);
	
	
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		cout << "Case:" << CASE << endl;
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini
