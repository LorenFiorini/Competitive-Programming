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

vector<int> prime;

void help() {
	int n = 10001;
	int p[n];
	REP (i, 0, n+1) p[i] = -1;
	REP (i, 2, n+1) {
		if (p[i] == -1) {
			for (int j = i; j < n+1; j += i) {
				p[j] = 0;
			}
			p[i] = 1;
		}
	}
	REP (i, 0, n+1) {
		if (p[i] == 1) {
			prime.push_back(i);
		}
	}
	//REP (i, 0, prime.size()) cout << prime[i] << "\n";
}


void solve () {
	int n;
	int l;
	cin >> n >> l;
	map<int, char> pri;
	map<int, char>::iterator it;
	vector<int> v(l);
	REP (i, 0, l) {
		int num;
		cin >> num;
		v[i] = num;
		//cout << v[i] << " ";
		for (int j = 0; j < prime.size() && num > 1; j++) {
			if (num % prime[j] == 0) {
				//cout << prime[j] << " ";
				it = pri.find(prime[j]);
				if (it == pri.end()) {
					pri.insert(pair<int, char> (prime[j], 'A'));
					
				} /*else {
					v[i-1] /= prime[j];
					if (i == l-1) v[i] = prime[j];
				}*/
				num /= prime[j];
			}			
		}
	}
	int c = 0;
	for (it = pri.begin(); it != pri.end(); it++) {
		it->second += c;
		c++;
	}
	REP (i, 0, l) {
		it = pri.find(v[i]);
		cout << v[i] << " ";
		/*
		if (it != pri.end())
		cout << it->second;
		else 
		cout << " ";*/
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


