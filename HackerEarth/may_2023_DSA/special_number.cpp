#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define showmap(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";
#define showv(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define showmat(MAT) for (auto R_: MAT) {showv(R_);}

ll n, m = 10;
ll mod = 1e9 + 7;
vector<ll> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
map<ll, ll> mp;

void fun(vector<ll> &nums) {
	vector<vector<ll>> fac(n, vector<ll> (10, 0));
	for (int i = 0; i < n; i++) {
		ll num = nums[i];
		bool ok = 1;
		for (int j = 0; j < m; j++) {
			while (num > 1 && num % primes[j] == 0) {
				fac[i][j]++;
				num /= primes[j];
			}
			ok &= (fac[i][j] < 2);
		}
		if (!ok) continue;

		ll val = 0;
		for (ll j = 0; j < m; j++) {
			if (fac[i][j])
				val = val | (1 << j);
		}
		mp[val]++;
	}
	//showmat(fac);
	//for (auto P_: mp) {cout << P_.first << " " << P_.second << "\n";}
}

vector<vector<ll>> dp;
/*
vector<ll> dfs(vector<vector<ll>> &v, ll sz, ll pos, vector<ll> cur) {
	if (pos >= sz) return cur;
    if (dp[pos][0] != -1) return dp[pos];

    // without current element
	vector<ll> t = dfs(v, sz, pos+1,  cur);
    dp[pos][0] = t[0];
    dp[pos][1] = t[1];
    // with current element
	if ((cur[0] & v[pos][0]) == 0) {
        cur[0] |= v[pos][0];
        cur[1] = (cur[1] * v[pos][1]) % mod;
		t = dfs(v, sz, pos+1, cur);
        dp[pos][0] = (dp[pos][0] | t[0]);
        dp[pos][1] = (dp[pos][1] * t[1]) % mod;
	}
    
	t = dfs(v, sz, pos + 1, cur);
    dp[pos][0] = (dp[pos][0] | t[0]);
    dp[pos][1] = (dp[pos][1] * t[1]) % mod;
	
	return dp[pos];
}
*/

ll dfs(vector<vector<ll>> &v, ll sz, ll pos,  ll cur_fac) {
    if (pos >= sz) return 1LL;

    ll ans = 1LL;
    for (ll i = pos+1; i < sz; i++) {
        if ((cur_fac & v[i][0]) == 0) {
            ll tmp = dfs(v, sz, i, (cur_fac | v[i][0]));
            ans = (ans * (v[i][1] * tmp) % mod) % mod;
            
        }
    }
    //cout << pos << " " << ans << endl;
    return ans;
}

void solve(void) {
	ll ans = 0;
	cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	fun(nums);
	vector<vector<ll>> v;
	for (auto par: mp) {
		v.push_back({par.first, par.second});
        ans += par.second;
	}

/*
	ll sz = v.size();
    dp.resize(sz, vector<ll> (2, -1));
	vector<ll> t = dfs(v, sz, 0, {0, 1});
    showmat(dp);
*/
    //showmat(v);
    //cout << ans << endl;
    ll sz = v.size();
    dp.resize(sz, vector<ll> (2, -1));
    ans += dfs(v, sz, -1, 0);
    //for (int i = 0; i < sz; i++) {
    //    ans =  (ans + (v[i][0] * dfs(v, sz, i, v[i][0])) % mod) % mod;
    //    break;
    //    //cout << ans << endl;
    //}
//
    //ans = (ans + 1) % mod;


	cout << ans << endl;
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

// Lorenzo Fiorini

/*
 2 2 3 4
2
3
5
7

*/

