#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define SCd(t) scanf("%d",&t)
#define SClld(t) scanf("%lld",&t)
#define SCc(t) scanf("%c",&t)
#define SCs(t) scanf("%s",t)
#define SClf(t) scanf("%lf",&t) //double
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

struct coor {
	int x;
	int y;
};


void solve () {
	int ans;
	int n, m, q;
	cin >> n;
	vector<coor> v(n);
	REP (i, 0, n) cin >> v[i].x >> v[i].y;
	//----------
	cin >> m;
	vector<int> op(m);
	REP (i, 0, m) {
		int tmp;
		cin >> tmp;
		if (tmp > 2) {
			int temp;
			cin >> temp;
			tmp *= 10;
			tmp += temp;
		}
		op[i] = tmp;
	}
	//---------
	cin >> q;
	REP (i, 0, q) {
		int a, b;
		cin >> a >> b;
		int xx = v[b-1].x;
		int yy = v[b-1].y;
		REP (o, 0, a) 
		{
			if (op[o] == 1) {
				//Rotate clockwise 90°
				int tmp = xx;
				xx = yy;
				yy = -tmp;
			} else if (op[o] == 2) {
				//Rotate counter-clockwise 90°
				int tmp = xx;
				xx = -1 * yy;
				yy = tmp;
			} else {
				int lineP = op[o] % 10;
				if ((op[o] / 10) == 3) {
					//Rotate plane through x = p
					int tmp = 2 * lineP - xx;
					xx = tmp;			
				} else {
					//Rotate plane through x = p
					int tmp = 2 * lineP - yy;
					yy = tmp;
				}
			}
		}
		cout << xx << " " << yy << "\n";
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
