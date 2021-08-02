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
	int ans;
	int n, a, b;
	cin >> n; cin >> a; cin >> b;
	string s; cin >> s;
	int pa = 0, pb = 0;
	vector<int> A(a * 2, 0);
	vector<int> B(b, 0);
	
	REP (i, 1, n) 
	{
		//JUST A
		if (s[i-1] == '0' && s[i] == '0') {
			s[i-1] = '1';
			s[i] = '1';
			A[pa] = i; pa++;
			A[pa] = i + 1; pa++;
			i++;
		}
		if (pa >= (a * 2)) break;
	}
	REP (i, 0, n) 
	{
		//JUST B
		if (s[i] == '0') {
			B[pb] = i + 1;
			pb++;
		}
		if (pb >= b) break;
	}
	//------------------------------------
	if (a != 0 && b != 0) 
	{
		if (A[2*a - 1] != 0 && B[b - 1] != 0) {
			cout << "YES\n";
			FOR (i, 0, 2 * a, 2) {
				cout << A[i] << " " << A[i+1] << "\n";
			}
			REP (i, 0, b) {
				cout << B[i] << "\n";
			}
			return;
		} else {
			cout << "NO\n";
			return;
		}
	} 
	else if (a == 0 && B[b - 1] != 0) 
	{
		cout << "YES\n";
		REP (i, 0, b) {
			cout << B[i] << "\n";
		}
		return;
	}
	else if (b == 0 && A[2*a - 1] != 0) 
	{
		cout << "YES\n";
		FOR (i, 0, 2 * a, 2) {
			cout << A[i] << " " << A[i+1] << "\n";
		}
		return;
	}
	else 
	{
		cout << "NO\n";
	}
	
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int t; cin >> t;
	//while (t--) 
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name


