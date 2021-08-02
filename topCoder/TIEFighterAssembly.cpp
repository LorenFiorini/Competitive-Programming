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


class TIEFighterAssembly {
	
public:
	 int assemble(string salvagedParts) {
		int n = salvagedParts.size();
		vector<int> v(3, 0);
		REP (i, 0, n) {
			if (salvagedParts[i] == '|') v[0]++;
			else if (salvagedParts[i] == '-') v[1]++;
			else if (salvagedParts[i] == 'O') v[2]++;
		}
		v[0] /= 2;
		v[1] /= 2;
		int ans = min(min(v[0], v[1]), v[2]);
		return ans;
	}
};

/* Test
int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//parameters 
	int a;
	
	name tmp;
	type ans = tmp.method(a);
	cout << ans;
	return 0;
} 
*/
