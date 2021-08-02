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
	int n;
public:
	bool check(vector <string> reels, vector<int> v) {
		REP (i, 0, n) {
			if (reels[i][v[i]] != 'c') return true;
		}
		return false;		
	}

	int win(vector <string> reels, vector <int> steps) {
		int ans = -1;
		n = steps.size();
		vector<int> v(n, 0);
		vector<int> s(n);
		REP (i, 0, n) {
			//Num of elements per reel
			s[i] = reels[i].size();
			steps[i] %= s[i];
			if (steps[i] == 0 && reels[i][0] != 'c') return -1;
		}
		do {
			REP (i, 0, n) {
				v[i] += steps[i];
				v[i] %= s[i];
			}
			ans++;
		} while (check(reels, v));
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
