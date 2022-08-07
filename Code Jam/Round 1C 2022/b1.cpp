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

bool check(string s) {
	set<char> st;
	int m = len(s);
	char c = s[0];
	rep(i,1,m+1) {
		if (i == m || s[i] != s[i-1]) {
			if (st.find(c) != st.end()) return false;
			st.insert(c);			
			if (i < m) c = s[i];
		}
	}
	return true;
}

void put(string word, list<string> &ls, queue<string> &later) {
	int m = len(word);
	each(it, ls) {
		if (word[m-1] == (*it)[0]) {
			ls.insert(it, word);
			return;
		}
		int sz = (*it).size();
		if (word[0] == (*it)[sz-1]) {
			it++;
			ls.insert(it, word);
			return;
		}
	}
	later.push(word);
}

void solve () {
	int n;
	cin >> n;
	vstr v(n);	
	rep(i,0,n) cin >> v[i];
	
	map<char, int> cool;
	queue<string> q;
	rep(i,0,n) {
		
		if (check(v[i])) {show("IMPOSSIBLE");return;}
		
		int sz = len(v[i]);
		if (v[i][0] == v[i][sz-1]) {
			cool[v[i][0]] += len(v[i]);
		} else {
			q.push(v[i]);
		}
	}
	
	string ans = q.front(); q.pop();
	while (!q.empty()) {
		int many = len(q);
		queue<string> nxt;
		while (!q.empty()) {
			string t = q.front();
			q.pop();
			int nans = len(ans);
			int nt = len(t);
			if (ans[0] == t[nt-1]) {
				ans = t + ans;
				if (cool[ans[0]] > 0) {
					string eq(cool[ans[0]], ans[0]);
					ans = eq + ans;
					cool[ans[0]] = 0;
				}
			} else if (ans[nans-1] == t[0]) {
				ans += t;
				if (cool[ans[nans-1]] > 0) {
					string eq(cool[ans[nans-1]], ans[nans-1]);
					ans = eq + ans;
					cool[ans[nans-1]] = 0;
				}
			} else {
				nxt.push(t);
			}
		}
		
		if (many == len(nxt)) {
			string t = nxt.front();
			nxt.pop();
			ans+= t;
		}
		q.swap(nxt);
		
	}
	each(it, cool) {
		if (it->ss > 0){
			string eq(it->ss, it->ff);
			ans += eq;
		}
		
	}
	
	if (check(ans)) {
		show(ans);
	} else {
		show("IMPOSSIBLE");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
