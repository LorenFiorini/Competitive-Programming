#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";


void solve (void) {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Number -> {left, right}
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		if (mp.find(a[i]) == mp.end()) {
			mp[a[i]] = {i, i, 0};
		} else {
			mp[a[i]][1] = i;
		}
	}

	for (int c = 1; c <= k; c++) {
		if (mp.find(c) == mp.end()) {
			cout << 0 << " ";
			continue;
		}
		
		if (mp[c][2] == 0) {
			mp[c][2] = 1;
			auto it = mp.find(c); it++;
			while (it != mp.end() && it->first > c) {
				mp[c][0] = min(mp[c][0], it->second[0]);
				mp[c][1] = max(mp[c][1], it->second[1]);
				if (it->second[2] == 1) break;
				it++;
			}
		}
		int l = mp[c][0], r = mp[c][1];
		int ans = (r - l + 1) * 2;
		cout << ans << " ";

	}
	cout << endl;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return (0);
}
/**
		int l = -1, r = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == c) {
				l = i;
				break;
			}
		}
		for (int i = n-1; i >= 0; i--) {
			if (a[i] == c) {
				r = i;
				break;
			}
		}
		if (l == -1) continue;
		int w = 0;
		for (int i = l; i <= r; i++) {
			if (a[i] == c) w++;
		}
		int h = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == c) h++;
		}
		ans += w + h;
*/
/**
 * By Lorenzo Fiorini
 * 
 * Contact
 * 	- linkedin.com/in/lorenfiorini/
 *	- github.com/LorenFiorini
*/ 

/*C.
 Colorful Table
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers n
 and k
. You are also given an array of integers a1,a2,…,an
 of size n
. It is known that for all 1≤i≤n
, 1≤ai≤k
.

Define a two-dimensional array b
 of size n×n
 as follows: bi,j=min(ai,aj)
. Represent array b
 as a square, where the upper left cell is b1,1
, rows are numbered from top to bottom from 1
 to n
, and columns are numbered from left to right from 1
 to n
. Let the color of a cell be the number written in it (for a cell with coordinates (i,j)
, this is bi,j
).

For each color from 1
 to k
, find the smallest rectangle in the array b
 containing all cells of this color. Output the sum of width and height of this rectangle.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers n
 and k
 (1≤n,k≤105
) — the size of array a
 and the number of colors.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤k
) — the array a
.

It is guaranteed that the sum of the values of n
 and k
 over all test cases does not exceed 105
.

Output
For each test case, output k
 numbers: the sums of width and height of the smallest rectangle containing all cells of a color, for each color from 1
 to k
.
*/