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


class A0Paper {
	
public:
    string canBuild(vector <int> A) {
		string ans = "Impossible";
		int n = A.size();
		int sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			sum += A[i];
			if (i > 0) sum /= 2;
		}
		if (sum > 0) ans = "Possible";
		return ans;
	}
};


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> A = {0,1,2};
	
	A0Paper tmp;
	cout << tmp.canBuild(A) << "\n";
	
	return 0;
} 
