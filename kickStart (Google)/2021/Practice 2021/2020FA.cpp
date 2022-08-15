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
	int n, x;
	cin >> n >> x;
	vector<int> ans(n+1);
	int p = 1;
	queue<pair<int, int>> q;
	REP (i, 1, n + 1) 
	{
		int tmp;
		cin >> tmp;
		if (tmp <= x) {
			ans[p] = i;
			p++;
		} else {
			q.push(pair<int, int> (i, tmp - x));
		}
	}
	while (q.size() > 1) 
	{
		int mon = q.front().second;
		int pos = q.front().first;
		mon -= x;
		if (mon <= 0) {
			ans[p] = pos;
			p++;
		} else {
			q.push(pair<int,int> (pos, mon));
		}
		q.pop();
	}
	if (q.size() == 1) ans[p] = q.front().first;
	REP (i, 1, n+1) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}
