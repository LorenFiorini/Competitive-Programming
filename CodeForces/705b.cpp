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

int h, m;
vector<int> tup(5, 0);
//vector<int> tdown(5, 0);

bool valid (vector<int> v) {
	int uval[5] = {3,4,6,7,9};
	REP (i, 0, 5) {
		if (i == 2) continue; 
		REP (j, 0, 5) {
			if (v[i] == uval[j]) return false;
		}
		if (v[i] == 2) v[i] = 5;
		if (v[i] == 5) v[i] = 2;
	}
	int mm = v[0] + v[1] * 10;
	int hh = v[4] + v[3] * 10;
	if (mm >= m || hh >= h) return false;
	return true;
}

void show(vector<int> v) {
	REP (i, 0, 5) {
		if (i == 2) {
			cout << ":";
			continue;
		}
		cout << v[i];
	}
	cout << "\n";
}

void update () {
	int mm = tup[4] + tup[3] * 10;
	int hh = tup[1] + tup[0] * 10;
	mm++;
	if (mm == m) {
		tup[4] = 0;
		tup[3] = 0;
		hh++;
	} else {
		tup[4] = mm % 10;
		tup[3] = mm / 10;
	}
	if (hh == h) {
		tup[0] = 0;
		tup[1] = 0;
	} else {
		tup[1] = hh % 10;
		tup[0] = hh / 10;
	}/*
	mm = tdown[4] + tdown[3] * 10;
	hh = tdown[1] + tdown[0] * 10;
	mm--;
	if (mm < 0) {
		tdown[4] = m % 10 - 1;
		tdown[3] = m / 10 - 1;
		hh--;
	} else {
		tdown[4] = mm % 10;
		tdown[3] = mm / 10;
	}
	if (hh < 0) {
		tdown[1] = h % 10 - 1;
		tdown[0] = h / 10 - 1;
	} else {
		tdown[1] = hh % 10;
		tdown[0] = hh / 10;
	}*/
	return;
}

void solve () {
	cin >> h >> m;
	string s; cin >> s;
	REP (i, 0, 5) {
		if (i == 2) continue;
		tup[i] = s[i] - '0';	
		//tdown[i] = s[i] - '0';	
		//cout<< tup[i];	
	}
	while (1) {
		if (valid(tup)) {
			show(tup);
			return;
		}
		/* else if (valid(tdown)) {
			show(tdown);
			return;
		}*/
		update();
	}
	
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

