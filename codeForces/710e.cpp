#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	int ans;
	int n;
	cin >> n;
	set<int> li;
	set<int>:: iterator it;
	REP (i, 1, n+1) li.insert(i);
	vector<int> q(n);
	vector<int> p(n,0);
	REP (i,0,n) {
		cin >>q[i];
		it = li.find(q[i]);
		if (it != li.end()){
			li.erase(it);
		}
		if (i== 0) p[i] = q[i];
		else if (q[i] > q[i-1]) p[i] = q[i];
	}
	vector<int> v;
	FOREACH(it, li){
		v.push_back(*it);
	}	
	sort(all(v));
	int sz = v.size();
	int pp = 0;
	REP (i, 0, n) {
		if (p[i] != 0) {
			cout << p[i] << " ";
		} else {
			cout << v[pp] << " ";
			pp++;
		}
	}
	pp--;
	cout << "\n";
	REP (i, 0, n) {
		if (p[i] != 0) {
			cout << p[i] << " ";
		} else {
			cout << v[pp] << " ";
			pp--;
		}
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

