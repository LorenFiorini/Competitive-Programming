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


class SlotMachineHacking {
	
public:
	 int win(vector <string> reels, vector <int> steps) {
		int n = steps.size();
		vector<int> rem(n, 0);
		vector<int> mod(n);
		REP (i, 0, n) {
			while (reels[i][rem[i]] != 'c') {
				//position of 'c'
				rem[i]++;
			}
		}
		REP (i, 0, n) {
			//Num of elements per reel
			mod[i] = reels[i].size();
			//rotation number
			//steps[i] %= mod[i];			
		}
		int summod = mod[0];
		int ans = rem[0];
		REP (i, 1, n) {
			//ans = rem[i - 1];
			while (ans % mod[i] != rem[i]) {
				//if (ans % mod[i] == rem[i]) break;
				ans += summod;
			}
			summod += mod[i];
		}
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
