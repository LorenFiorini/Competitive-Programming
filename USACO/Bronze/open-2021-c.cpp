#include <bits/stdc++.h>
using namespace std;
#define ll int
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define FOR(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> f(n, vector<ll> (m, 0));
	
	map<int, vector<int> > r;
	map<int, vector<int> > c;
	map<int, vector<int> > :: iterator ti;
	
	ll sz = 0;
	map<pair<int, int>, int> mp;
	map<pair<int, int>, int>:: iterator it;
	// input
	REP (i, 0, n) {
		string s;
		cin >> s;
		REP (j, 0, m) {
			if (s[j] == 'C') {
				
				f[i][j] = 1;
				pair<int, int> par = make_pair(i, j);
				it = mp.find(par);
				if (it == mp.end()) {
					mp.insert(make_pair( par, sz));
				}
				// row
				ti = r.find(i);
				if (ti == r.end()) {
					vector<int> tmp;
					tmp.push_back(sz);
					r.insert(make_pair(i, tmp));
				} else {
					ti->second.push_back(sz);
				}
				
				// col
				ti = c.find(j);
				if (ti == c.end()) {
					vector<int> tmp;
					tmp.push_back(sz);
					c.insert(make_pair(j, tmp));
				} else {
					ti->second.push_back(sz);
				}
				
				sz++;
			} else if (s[j] == '.') {
				f[i][j] = -1;
			}
		}
	}
	// count
	set<int> iii;
	set<int> :: iterator iti;
	set<int> jjj;
	set<int> :: iterator itj;
	vector<vector<bool>> a(sz, vector<bool> (sz, false));
	REP (i, 0, n) {
		REP (j, 0, m) {
			iti = iii.find(i);
			itj = jjj.find(j);
			if (f[i][j] == 0) 
			{
				// ROW OF COWS
				ti = r.find(i);
				int len = ti->second.size();
				vector<int> row(len);
				if (len) REP (pos, 0 , len ) row[pos] = ti->second[pos];
					// own row
				if (iti == iii.end()) {
					REP (p1, 0, len) REP (p2, p1 + 1, len){
						int I = row[p1];
						int J = row[p2];
						a[I][j] = true;						
					}
				}
				// COL OF COWS
				ti = c.find(i);
				int len2 = ti->second.size();
				vector<int> col(len2);
				if (len2) REP (pos, 0 , len2) col[pos] = ti->second[pos];
					// own col
				if (itj == jjj.end()) {
					REP (p1, 0, len2) REP (p2, p1 + 1, len2){
						int I = col[p1];
						int J = col[p2];
						a[I][J] = true;						
					}
				}
				// BETWEEN COL AND ROW
				REP (vr, 0, len) {
					REP (vc, 0, len2) {
						int I = row[vr];
						int J = col[vc];
						a[I][J] = true;	
					}
				}
				
				iii.insert(i);
				jjj.insert(j);
			}
		}
	}	
	
	
	//ll sz = a.size();
	REP (i, 0, sz) {
		REP (j, i, sz) {
			if (a[i][j]) ans++;
		}
	}
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}


