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
#include <iomanip>
using namespace std;
// My Favorite Macros
typedef int64_t ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(i_, a_, b_, in_) for (int i_ = a_; i_ < (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

ll gcd_ll(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd_ll(b, a % b);
}

void solve () {
	// Input
	long long N, X, Y;
	long long cycle = 1;
	cin >> N >> X >> Y;
	vector<long long> P(N-1), T(N-1);
	rep(i, 0, N-1) {
		cin >> P[i] >> T[i];
		cycle = cycle * P[i] / gcd_ll(cycle, P[i]);
	}
	// cout << cycle << "\n";

	vector<long long> v(cycle);
	for (int i = 0; i < cycle; ++i) {
		long long t = i + X;
		long long x = 0;
		while (x < N-1) {
			t = t + (P[x] - t % P[x]) % P[x];
			if (t % P[x] == 0) {
				t += T[x];
				x++;
			} else {
				t++;
			}
		}
		v[i] = t + Y;
	}
	// showv(v);

	long long Q;
	cin >> Q;
	vector<long long> q(Q);
	rep(i, 0, Q) {
		cin >> q[i];
		long long ans = v[q[i] % cycle] + (q[i] - q[i] % cycle);
		// cout << i << ": ";
		cout << ans << "\n";

		// cout << q[i] % cycle << " " << v[q[i] % cycle] << " " << q[i] - q[i] % cycle << "\n\n";
	}	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */

/*
Problem Statement Takahashi is initially at his house and is about to visit Aoki's house. There are N bus stops numbered 1 to N between the two houses, and Takahashi can move between them in the following ways: He can walk from his house to bus stop 1 in X units of time. For each i=1,2,…,N−1, a bus departs from bus stop i at each time that is a multiple of P i ​ , and by taking this bus, he can get to bus stop (i+1) in T i ​ units of time. Here, the constraints guarantee that 1≤P i ​ ≤8. Takahashi can walk from bus stop N to Aoki's house in Y units of time. For each i=1,2,…,Q, process the following query. Find the earliest time that Takahashi can arrive at Aoki's house when he leaves his house at time q i ​ . Note that if he arrives at a bus stop exactly at the departure time of a bus, he can take that bus. Constraints 2≤N≤10 5 1≤X,Y≤10 9 1≤P i ​ ≤8 1≤T i ​ ≤10 9 1≤Q≤2×10 5 0≤q i ​ ≤10 9 All input values are integers. Input The input is given from Standard Input in the following format: N X Y P 1 ​ T 1 ​ P 2 ​ T 2 ​ ⋮ P N−1 ​ T N−1 ​ Q q 1 ​ q 2 ​ ⋮ q Q ​ Output Print Q lines. For each i=1,2,…,Q, the i-th line should contain the answer to the i-th query.
*/

/* 
Sample Input 1
4 2 3
5 4
6 6
3 1
7
13
0
710511029
136397527
763027379
644706927
447672230

Sample Output 1
34
22
710511052
136397548
763027402
644706946
447672250

For the first query, Takahashi can move as follows to arrive at Aoki's house at time 34. Leave his house at time 13. Walk from his house and arrive at bus stop 1 at time 15. Take the bus departing from bus stop 1 at time 15 and arrive at bus stop 2 at time 19. Take the bus departing from bus stop 2 at time 24 and arrive at bus stop 3 at time 30. Take the bus departing from bus stop 3 at time 30 and arrive at bus stop 4 at time 31. Walk from bus stop 4 and arrive at Aoki's house at time 34.
For the second query, Takahashi can move as follows and arrive at Aoki's house at time 22. Leave his house at time 0. Walk from his house and arrive at bus stop 1 at time 2. Take the bus departing from bus stop 1 at time 5 and arrive at bus stop 2 at time 9. Take the bus departing from bus stop 2 at time 12 and arrive at bus stop 3 at time 18. Take the bus departing from bus stop 3 at time 18 and arrive at bus stop 4 at time 19. Walk from bus stop 4 and arrive at Aoki's house at time 22.

*/
