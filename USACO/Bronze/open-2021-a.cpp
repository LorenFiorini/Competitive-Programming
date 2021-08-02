#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD (1e9 + 7)
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


vector<pair<int, int>> v;
int n, l;

void ri () {
	cin >> n >> l;
	map<int, int> mp;
	map<int, int>:: iterator it;
	REP (i, 0, n) {
		int tmp;
		cin >> tmp;
		it = mp.find(tmp);
		if (it == mp.end()) {
			mp.insert({tmp, 1});
		} else {
			it->second++;
		}
	}	
	for (it = mp.begin(); it != mp.end(); it++) {
		v.push_back(make_pair(it->first, it->second));
	}
	sort(all(v));
}


void solve () {
	ri();
	int ans = 0;
	int m = v.size();
	int i = n;
	RREP (po, m, 0) {
		int f = v[po].first;
		int s = v[po].second;
		i -= s;
		/*cout << f << " " << s << "\n";
		cout << i << "\n";
		cout << ans << "\n\n";*/
		int index = 0;
		if (f <= n - i) 
		{
			index = f;
			if (s <= l && f+1 <= n - 1) {
				index++;
			} else if (s > l){
				int num = n - (i + (s - l)); // ELEMENTOS
				if (f + 1 <= num) index++;
			}
			ans = max(ans, index);
		} 
		/*else {
			//cuando podes sumar uno parcialmente a S
			// parte de los paper with F citations
			// son F
		}*/
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
