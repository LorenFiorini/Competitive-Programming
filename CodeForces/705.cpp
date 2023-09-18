
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

vector<int> v(25);

void help () {
	int num[5] = {0, 1, 2, 5, 8};
	REP (i, 0, 5) {
		REP (j, 0, 5) {
			int tmp = num[i] * 10 + num[j];
			v[i * 5 + j] = tmp;
		}
	}
	return;
}

int turn (int num) {
	int d = num % 10;
	if (d == 2) d = 5;
	else if (d == 5) d = 2;
	int ans = d * 10;
	
	d = num / 10;
	if (d == 2) d = 5;
	else if (d == 5) d = 2;
	
	ans += d;
	return ans;
}

void solve () {
	int ans;
	int h, m;
	cin >> h >> m;
	string s; cin >> s;
	int hh = s[0] - '0'; hh *= 10;
	hh += s[1] - '0';
	int mm = s[3] - '0'; mm *= 10;
	mm += s[4] - '0';
	int ph = 0;
	int pm = 0;
	bool okh = false; bool okm = false;
	REP (i, 0, 25) {
		if (v[i] >= hh && !okh) {
			ph = i;
			okh = true;
		}
		if (v[i] >= mm && !okm) {
			pm = i;
			okm = true;
		}
	}
	int min = turn(v[ph]);
	int ho = turn(v[pm]);
	while (1) {
		min = turn(v[ph]);
		ho = turn(v[pm]);
		if (v[pm] < m && v[ph] < h && min < m && ho < h) {
			cout << v[ph]/10 << v[ph]%10 << ":" << v[pm]/10 << v[pm]%10;
			break;
		} 
		if (v[pm] >= m) {
			pm = -1;
			ph++;
		}
		if (v[ph] >= h) {
			ph = 0;			
		}
		pm++;
		pm %= 25;
		ph %= 25;
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	help();
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name
