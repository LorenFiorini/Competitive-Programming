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

int n, q;
vector<int> v(50);

void show () {
	REP (i, 0, n) 
		cout << v[i] << " ";
	cout << endl;
    fflush(stdin);
    int ans; cin >> ans;
}

int ask(int i) {
    cout << i-1 << " " << i << " " << i+1 << endl;
    fflush(stdin);
    int ans; cin >> ans;
    return ans - i;
}

void swap(int i, int p) {
    int tmp = v[i];
    v[i] = v[p];
    v[p] = tmp;
}

void solve () {
    REP (i,0,n) v[i] = i + 1;
	REP (i, 1, n - 1) {
        int ans = ask(i + 1);
        if (ans) {
            swap(i, i + ans);
            int rev = 1;
            int tmp = -1;
            while (tmp != 0 && i+1 - rev > 1) {
                tmp = ask(i+1 - rev);
                swap(i - rev , i - rev + tmp);
                rev++;
            }
        }
            
    }
	show();
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; int c = 1;
    cin >> t >> n >> q;
	v.resize(n);
	while (c <= t) {
		solve();
		c++;
	}
	
	return 0;
}
