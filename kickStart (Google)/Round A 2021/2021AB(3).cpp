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


void pr(vector<vector<int>> &v) {
	cout << "\n";
	REP (i, 0, v.size()){
		REP (j,0,v[0].size()) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}


int countL(vector<vector<int>> &v) {
	int r = v.size();
	int c = v[0].size();
	// PREFIX SUM 
	// horizontal 
	vector<vector<int>> row(r, vector<int> (c, 0));
	REP (i, 0, r) REP (j, 0, c) {
		if (v[i][j]) {
			row[i][j] = v[i][j];
			if (j > 0) row[i][j] += row[i][j-1];
		}
	}
	
	// vertical
	vector<vector<int>> col(r, vector<int> (c, 0));
	REP (j, 0, c) REP (i, 0, r) {
		if (v[i][j]) {
			col[i][j] = v[i][j];
			if (i) col[i][j] += col[i-1][j];
		}
	}
	/*
	cout << "\nPrefix sum column";
	pr(col);
	
	cout << "\nPrefix sum row";
	pr(row);
	*/
	
	// SEARCH L (up, left) twice as tall
	int ans = 0;
	REP (i, 0, r) REP (j, 0, c) {
		int hor = row[i][j];
		int ver = col[i][j];
		int mul = 0;
		while (hor >= 2 + mul && ver >= 2 * (2 + mul)) {
			ans++;
			mul++;
		}
		mul= 0;
		while (ver >= 2 + mul && hor >= 2 * (2 + mul)) {
			ans++;
			mul++;
		}
	}
	return ans;
}
/*
 *  0 1 0 0
 *  0 1 0 0
 *  0 1 0 1
 *  1 1 0 1
 *  0 0 0 1
 *  0 0 1 1 
 * 
 * 
 * */
/*
void rotate(vector<vector<int>> &v, vector<vector<int>> &rot) {
	int r = v.size();
	int c = v[0].size();
	//vector<vector<int>> rot(c, vector<int> (r));
	REP (i, 0, r) REP(j, 0, c) {
		rot[j][r-1 - i] = v[i][j];
	}
	return;
}*/
// mirror not rotate;


void reflectionY(vector<vector<int>> &v) {
	int r = v.size();
	int c = v[0].size();
	REP (i, 0, r) REP (j, 0, c / 2) {
		int tmp = v[i][j];
		v[i][j] = v[i][c - 1 - j];
		v[i][c-1 - j] = tmp;
	}
	return;
}

void reflectionX(vector<vector<int>> &v) {
	int r = v.size();
	int c = v[0].size();
	REP (j, 0, c) REP (i, 0, r / 2) {
		int tmp = v[i][j];
		v[i][j] = v[r-1 - i][j];
		v[r-1 - i][j] = tmp;
	}
	return;
}

void solve () {
	int ans = 0;
	int r, c;
	cin >> r >> c;
	vector< vector<int> > v(r, vector<int> (c, 0));
	REP (i, 0, r) REP (j, 0, c) cin >> v[i][j];
	
	//pr(v);
	ans += countL(v);
	//cout << ans << "\n";	
	
	//rotate(v, rot);
	reflectionY(v);
	//pr(v);
	ans += countL(v);
	//cout << ans << "\n";
	
	//rotate(rot, v);
	reflectionX(v);
	//pr(v);
	ans += countL(v);
	//cout << ans << "\n";
	
	//rotate(v, rot);
	reflectionY(v);
	//pr(v);
	ans += countL(v);
	
	
	cout << ans << "\n";
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

