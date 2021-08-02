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
/*
vector<int[]> v(9);

int c1[1] = {1};
int c2[2] = {4, 8, 6, 2};
int c3[3] = {9, 7, 1, 3};
int c4[4] = {6, 4};
int c5[5] = {5};
int c6[6] = {6};
int c7[7] = {9, 3, 1, 7};
int c8[8] = {4, 2, 6, 8};
int c9[9] = {1, 9};

void help() {
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);
	v.push_back(c6);
	v.push_back(c7);
	v.push_back(c8);
	v.push_back(c9);
}
*/
ll power (ll a, ll b) {
	ll exp = (b % 4 == 0) ? 4 : b % 4;
	a %= 10;
	ll ans = pow(a, exp);
	return ans;
}



void solve () {
	ll ans;
	ll a,b,c;
	cin >> a >> b >> c;
	
	b = power(b , c);
	ans = power(a, b);
	
	cout << ans % 10 << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//help();
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

