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

bool check(string s, set<char> &mid) {
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
	bool ok = 1;
	if (st.size() > 1) {
		st.erase(s[0]);
		st.erase(s[m-1]);
		each(it, st) {
			ok &= mid.find(*it) == mid.end();
			mid.insert(*it);
		}
	}	
	return ok;
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
	
	//Node *root = new Node();
	
	bool ok = 1;
	set<char> beg;
	set<char> mid;
	set<char> en;
	
	rep(i, 0, n) {		
		ok &= check(v[i], mid);	
		int m = len(v[i]);
		
		if (ok && v[i][0] != v[i][m-1]) {
			//show("");
			//showp(v[i][0], v[i][m-1]);
			ok &= beg.find(v[i][0]) == beg.end();
			ok &= mid.find(v[i][0]) == mid.end();
			beg.insert(v[i][0]);
			
			ok &= en.find(v[i][m-1]) == en.end();
			ok &= mid.find(v[i][m-1]) == mid.end();
			en.insert(v[i][m-1]);
			
			each(it, mid) {
				ok &= en.find(*it) == en.end();
				ok &= beg.find(*it) == beg.end();
			}
		}
		if (!ok) {
			show("IMPOSSIBLE");
			return;
		}	
	}
	list<string> ls;
	ls.insert(ls.begin(), v[0]);
	queue<string> q;
	queue<string> later;
	
	rep(i,1,n) {
		int m = len(v[i]);
		if (v[i][0] == v[i][m-1]) {
			q.push(v[i]);
		} else {
			put(v[i], ls, later);
		}
	}
	
	
	while (!later.empty()) {
		int many = len(later);
		queue<string> nxt;
		while (!later.empty()) {
			string t = later.front();
			later.pop();
			put(t, ls, nxt);
		}
		if (many == len(nxt)) {
			string t = nxt.front();
			nxt.pop();
			ls.insert(ls.begin(), t);
		}
		later.swap(nxt);
	}
	while (!q.empty()) {
		int many = len(q);
		queue<string> nxt;
		while (!q.empty()) {
			string t = q.front();
			q.pop();
			put(t, ls, nxt);
		}
		if (many == len(nxt)) {
			string t = nxt.front();
			nxt.pop();
			ls.insert(ls.begin(), t);
		}
		q.swap(nxt);
	}
	
	string ans;
	each(it, ls) {
		ans += *it;
	}
	set<char> tmp;
	if (check(ans, tmp)) {
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
