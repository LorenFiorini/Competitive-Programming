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

int ask(int i) {
    cout << i-1 << " " << i << " " << i+1 << endl;
    cout << flush;
    //fflush(stdout);
    int ans; cin >> ans;
    return ans - i;
}

void solve () {
    list<int> li;
    list<int>::iterator it;
    li.push_back(1);
    li.push_back(2);
	REP (i, 1, n - 1) {
        int ans = ask(i + 1);
        int num = i+2; 
        if (ans == -1) {
            if (i%2) li.push_front(num);
            else li.push_back(num);
        } else if (ans == 0) {
            if (i%2) li.push_back(num);
            else li.push_front(num);
           
        } else {
            bool ok = false;
            for (it = li.begin(); it != li.end(); it++) {
				int th = *it;
                if ((th == i || th == i+1) && ok ){
                    li.insert(it, num);
                    break;
                }
				if (th == i || th == i+1) ok = true;
            }
        }
        li.reverse();
    }
    // Show
	for (it = li.begin(); it != li.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << flush;
    int answer; cin >> answer;
    if (answer == -1) t = 0;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
    cin >> t >> n >> q;
	while (t-->0) {
		solve();
	}
	
	return 0;
}
