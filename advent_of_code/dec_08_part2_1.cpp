#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
typedef long long ll;

ll scenic(vector<string> &v, ll r, ll c, ll n) {
	ll le = 1, ri = 1, down = 1, up = 1;

	// to left
	while (c + le < n-1 && v[r][c] > v[r][c + le]) le++;
	//if (c + le == n) le--;

	// to right
	while (c - ri > 0 && v[r][c] > v[r][c - ri]) ri++;
	//if (c - ri < 0) ri--;
	
	// to down
	while (r + down < n-1 && v[r][c] > v[r + down][c]) down++;
	//if (r + down == n) down--;

	// to up
	while (r - up > 0 && v[r][c] > v[r - up][c]) up++;
	//if (r - up < 0) up--;

	ll ans = le * ri * down * up;
	return ans;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n = 100;
	vector<string> v(n);
	for (auto &a: v) cin >> a;

	ll ans = 0;
	for (ll i = 1; i < n-1; i++) {
		for (ll j = 1; j < n-1; j++) {
			ll val = scenic(v, i, j, n);
			if (val > ans) {
				ans = max(ans, val);
			}
			//cout << val << " ";
		}
		//cout << endl;
	}

	cout << ans << endl;
	return 0;
}

// Lorenzo Fiorini

// 609120 -> too high
// 2464 -> too low
// 2240 
// 1470
// 1920
// 9720 -> too low

// 255990 -- >That's not the right answer.
// 284256 --> Neither

// 548550 -> That's not the right answer.


