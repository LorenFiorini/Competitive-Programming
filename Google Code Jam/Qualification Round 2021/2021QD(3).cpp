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

int t, n, q;

int query(int l, int r, int nw) {
    cout << l << " " << r << " " << nw << endl;
    cout << flush;
    int ans; cin >> ans;
    return ans;
}

void solve () {
	list<int> x;
	list<int>::iterator itr;
	list<int>::iterator itl;
	
	REP (num, 1, n + 1) {
		if (num < 3) {
			x.push_back(num);
			continue;
		}
		bool ok = false;
		bool fi = false;
		itl = x.begin();
		for (itr = x.begin(); itr != x.end(); itr++) {
			if (!fi) {
				fi = true;
				continue;
			}
			int ans = query(*itl, *itr, num);
			if (ans == num) {
				x.insert(itr, num); ok=1;
				break;
			} else if (ans == *itl) {
				x.insert(itl, num); ok=1;
				break;
			} else if (ans == -1) {t=0; return;}
			itl++;
		}
		if (!ok) x.push_back(num);
    }
    /*
    vector<int> v(n, 0);
    int cnt = 1;
    FOREACH (itr, x){
		v[*itr - 1] = cnt;
		cnt++;
	}
    REP (i, 0, n) cout << v[i] << " ";*/
    FOREACH (itr, x) {
		cout << *itr << " "; 
	}
    
	cout << endl << flush;
    int answer; cin >> answer;
    if (answer == -1) t = 0;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c = 1;
    cin >> t >> n >> q;
	while (c <= t) {
		solve();
		c++;
	}
	
	return 0;
}

