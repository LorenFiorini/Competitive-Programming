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

/*
int getMin(vector<int> &v, int upper) {
	REP (i, 1, upper) {
		if (!v[i]) {
			v[i] = 1;
			return i;
		}
	}
}

int getMax(vector<int> &v, int upper) {
	RREP (i, upper, 1) {
		if (!v[i]) {
			v[i] = 1;
			return i;
		}
	}
}*/

void solve () {
	int ans;
	int n;
	cin >> n;
	vector<int> q(n+1, 0);
	REP (i, 1, n+1) cin >> q[i];
	vector<int> mn(n);
	vector<int> mx(n);
	//vector<int> un(n+1, 0);
	//vector<int> um(n+1, 0);
	//mn[0] = q[0]; mx[0] = q[0];
	set<int> mini;
	set<int> maxi;
	set<int>:: iterator it;
	set<int>:: reverse_iterator rit;
	REP (i, 1, n+1) {
		mini.insert(i);
		maxi.insert(i);
	}
	REP (i, 0, n) {
		if (q[i] != q[i+1]) {
			int num = q[i+1];
			mn[i] = num;
			mx[i] = num;
			it = mini.find(num);
			mini.erase(it);
			it = maxi.find(num);
			maxi.erase(it);
			//un[q[i+1]] = 1;
			//um[q[i+1]] = 1;
		} else {
			it = mini.begin();
			mn[i] = *it;
			mini.erase(it);
			for (rit = maxi.rbegin(); rit != maxi.rend(); rit++) {
				if (*rit < q[i]) {
					mx[i] = *rit;
					it = maxi.find(*rit);
					maxi.erase(it);
					break;
				}
			}				
		}
	}
	
	REP (i, 0, n) cout << mn[i] << " ";
	cout << "\n";
	REP (i, 0, n) cout << mx[i] << " ";
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


