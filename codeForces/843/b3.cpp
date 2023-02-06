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
#define showv(v, n) rep(index, 0, n) {cout << v[index] << " ";} cout << "\n";
#define showvp(v, n) rep(index, 0, n) {showp(v[index].ff, v[index].ss);}
#define showvv(vv, n, m) rep(row, 0, n) {showv(vv[row], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int n;

bool b_min(string s) {
	string A, B, C;
		
	if (s[0] == 'a') {
		// Try making B = "a"
		rep (i, 1, n - 1) {
			if (s[i] == 'a') {
				A = s.substr(0, i);
				//B = s.substr(i, 1);
				C = s.substr(i+1, n - (i+1));
				cout << A << " a " << C << endl;
				return 1;
			}
		}
	} else {
		// finding an 'a' for B string still works
		// A = 'b'

		// Try making B = "a"
		rep (i, 1, n - 1) {
			if (s[i] == 'a') {
				A = s.substr(0, i);
				C = s.substr(i+1, n - (i+1));
				cout << A << " a " << C << endl;
				return 1;
			}
		}


		// B = 'b'
		if (n == 3 && s[2] == 'b') {
			cout << "b b b" << endl;
			return 1;
		} else if (n > 3) {
			// cout << "b b ";
			cout << s[0] << " " << s[1] << " ";
			C = s.substr(2, n - 2);
			cout << C << endl;
			return 1;
		}
	}

	return 0;
}


bool b_max(string s) {
	string A, B, C;

	A = s.substr(0, 1);
	B = s.substr(1, n - 2);
	C = s.substr(n-1, 1);
	if (B >= A && B >= C) {
		cout << A << " " << B << " " << C << endl;
		return 1;
	} else {
		return 0;
	}
	/*
	if (s[0] == 'a' && s[n-1] == 'a') {
		B = s.substr(1, n - 2);
		
		cout << "a " << B << " a" << endl;
		return 1;
	}

	// A = a until s[i] != 'a'
	if (s[0] == 'a') {
		//int id = 0;
		//while (id < n && s[id] == 'a') id++;
		
		string B = s.substr(id, n-1 - id);
		string C = s.substr(n-1, 1);
		if (B > C) {
			rep (i, 0, id) cout << s[i]; cout << " ";
			cout << B << " " << C << endl;
			return 1;
		}

	} else {
		// A = b
		int id = 1;
		while (id < n && s[id] == 'a') id++;
		
		string A = s.substr(0, id);
		string B = s.substr(id, n-1 - id);
		if (B >= A) {
			cout << A << " " << B << " " << s[n-1] << endl;
			return 1;
		}
	}*/

	return 0;
}

void solve () {
	string s;
	cin >> s;
	n = len(s);

	// search for b <= min(a, c)
	if (b_min(s)) return ;

	if (b_max(s)) return ;

	
	show(":(");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
