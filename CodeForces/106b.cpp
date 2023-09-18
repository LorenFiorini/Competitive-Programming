
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
	string s;
	cin >> s;
    int n = s.size();
    string answer = "";
    bool out = false;
    bool ch = false;
    REP (i, 0, n) {
        if (!ch) {
            if (s[i] == '1') {
                if (out) {
                    ch = true;
                    i--;
                    out = false;
                    continue;
                }
                out = true;
                continue;
            } else {
                answer += s[i];
                out = false;
            }
        } else {
            if (s[i] == '0') {
                if (out) {
	                cout << "No\n";
                    return;
                }
                out = true;
                continue;
            } else {
                out = false;
                answer += s[i];
            }
        }
    }
	
	cout << "Yes\n";
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
