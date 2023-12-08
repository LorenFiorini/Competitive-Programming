
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
typedef int64_t ll;

// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_.first << " " << a_.second << "\n";} cout << "\n";


void solve () {
	int ans = 0;
	int n;
	cin >> n;
    vector<int> a(n);
    vector<int> vec(n, 3);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, vector<int> > pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    // 12, 13, 23
    int cond[3] = {0, 0, 0};

    for (auto it = pos.begin(); it != pos.end(); it++) {
        if (it->second.size() >= 2) {
            ans++;
            vec[it->second[0]] = ans;
        }
        if (ans == 2) {
            showv(vec);
            return;
        }
    }
    show(-1);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	{
    	solve();
        // cout << endl;
    }
	
	return 0;
}

/* Lorenzo Fiorini */
