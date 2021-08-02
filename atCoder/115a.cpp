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
int setBits[1048577];

void help(int ene) {
	REP (i, 0, ene + 1) {
		setBits[i] = __builtin_popcount (i);
		//if (i < 100) cout << i << " -  " << setBits[i] << "\n";
	}
}*/

int decimal (string str, int m) {
	int ans = 0;
	REP (i, 0, m){
		if (str[i] == '1') {
			ans += pow(2, m - 1 - i);
		}
	}
	return ans;
}

void solve () {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	int pp = pow(2, m);
	help(pp);
	//vector<string> v(n);
	vector<int> v(n);
	REP (i, 0, n) {
		string str;
		cin >> str;
		v[i] = decimal(str, m);
		cout << v[i] << "\n";
	}
	/*
	REP (i, 0, n - 1) {
		REP (j, i + 1, n) {
			ans++;
			REP (k, 0, pp ) {
				int t1 = setBits[(v[i] + k) % pp];
				int t2 = setBits[(v[j] + k) % pp];
				if (t1 == t2) {
					ans--;
					break;
				}
			}			 
		}
	}*/
	REP (i, 0, n) {
		REP (j, i + 1, n) {
			int ok = maybe;
			REP (k, 0, pp ){
				//compare binary representation of Vi ans Vj to k
				if (not) break and not ok;
			}
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
//$ sudo g++ -o name name.cpp
//$ ./name

