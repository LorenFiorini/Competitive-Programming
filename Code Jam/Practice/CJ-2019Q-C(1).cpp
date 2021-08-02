#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<b ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

vector<int> primes;

void help() {
	int n = 10001;
	int nums[n];
	REP (i, 0, n+1) nums[i] = 0;
	REP (i, 2, n+1) {
		if (!nums[i]) {
			primes.push_back(i);
			FOR (j, 2*i, n+1, i) {
				nums[j] = 1;
			}
		}
	}
}


void solve () {
	int ans;
	int n, l;
	cin >> n >> l;
	map<int, char> let;
	map<int, char>::iterator it;
	vector<int> v(l+1, 1);
	
	REP (i, 1, l + 1) 
	{
		int num;
		cin >> num;
		v[i] = num;
		REP (j, 0, primes.size() && num > 1) 
		{
			if (num % primes[j] == 0) {
				it = let.find(primes[j]);
				if (it == let.end()) {
					let.insert(pair<int, char> (primes[j], 'A'));
				} else {
					// It was found
					if (i == 2) {
						v[0] = v[1] / primes[j];
						//v[1] = primes[j];
					}
				}
				num /= primes[j];
			}
		}
	}
	REP (i, 1, l+1) {
		v[i] /= v[i - 1];
	}
	int c = 0;
	FOREACH(it, let)
	{
		it->second += c;
		c++;
		//cout << it->first << " " << it->second << "\n";
	}
	REP (i, 0, l+1) {
		it = let.find(v[i]);
		cout << it->second;
	}
	
	
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	help();
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}
