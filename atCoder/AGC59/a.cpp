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
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(n+1);
    for (int i = 0; i < n; i++) {
    	v[i+1] = v[i] + (i? (s[i-1] != s[i]): 1);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = v[r] - v[l-1] - 1;


        cout << ans  << endl;
    }

    return 0;
}
/*
int dp[100005][3];
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i + 1][j] = dp[i][j];
        }
    	if (i && s[i] == s[i-1]) continue;
    	int id = s[i] - 'A';
        dp[i + 1][(id + 1) % 3]++;
        dp[i + 1][(id + 2) % 3]++;
    }
    //show
    for (int j = 0; j < 3; j++) {
    	for (int i = 0; i <= n; i++) {
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = 1e9;

        //bool z
        vector<int> c(3);
        for (int j = 0; j < 3; j++) {
            //ans = max(ans, dp[r][j] - dp[l - 1][j]);
            //if (dp[r][j] - dp[l - 1][j] != 0) ans++;
            c[j] = dp[r][j] - dp[l - 1][j];
            ans = min(ans, c[j]);
        }

        //ans = cbrt(ans);
        //cout << r - l + 1 - ans << " ";
        cout << ans  << endl;
        //for (int A: c) cout << A << " "; cout << endl;
    }
    return 0;
}
*/

/*
int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> cnt(n + 1, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cnt[i + 1] = cnt[i];
    cnt[i + 1][s[i] - 'A']++;
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    vector<int> c(3);
    for (int j = 0; j < 3; j++) c[i] = cnt[r][i] - cnt[l - 1][i];
    int ans = min(c[0], min(c[1], c[2]));
    cout << ans << endl;
  }
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      a[i] = 0;
    } else if (s[i] == 'B') {
      a[i] = 1;
    } else {
      a[i] = 2;
    }
  }
  wavelet_matrix<int, 3> wm(a);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    int cnt[3] = {0, 0, 0};
    for (int j = 0; j < 3; j++) {
      cnt[j] = wm.rank(r, j) - wm.rank(l, j);
    }
    int ans = 0;
    for (int j = 0; j < 3; j++) {
      ans += cnt[j] * (cnt[j] - 1) / 2;
    }
    cout << ans << endl;
  }
}
*/