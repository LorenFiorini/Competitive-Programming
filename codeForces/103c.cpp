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

struct ab {
	int a;
	int b;
};

int largest_cycle (vector<int> ch, vector<ab> ed, int br, int start)
{
	int ans = ch[start];
	RREP (i, start, br) {
		
		if (i == br + 1) {
			if (br == 0) {
				ans += ed[i].b - ed[i].a + 1;
			}
			ans++;
			break;
		}
		ans += ed[i].a;
		ans += ch[i-1] - ed[i].b + 1;
		
	}
	return ans;
}


void solve () 
{
	int ans = 0;
	int n;
	cin >> n;
	vector<int> ch(n);
	vector<ab> edge(n);
	REP (i, 0, n) cin >> ch[i];
	REP (i, 0, n) cin >> edge[i].a;
	vector<int> br;
	REP (i, 0, n) {
		cin >> edge[i].b;
		if (edge[i].b == edge[i].a && i) br.push_back(i-1);
	}
	int start = n - 1;
	RREP (i, br.size(), 0) {
		ans = max(ans, largest_cycle(ch, edge, br[i], start));
		start = br[i];
		
	}
	cout << ans << "\n";
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

