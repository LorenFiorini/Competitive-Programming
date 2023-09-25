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


ll solve (void) {
	ll n;
	cin >> n;
	ll N = 2 * n - 1;
	vector<ll> v(2 * n - 1);
	for (ll i = 0; i < 2 * n - 1; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (n == 1) return 1;
	
	// n >= 3 and n is odd
	if (v[0] + v[N - 2] > v[N - 1]) {
		bool ok = 1;
		ll sum = v[0] + v[N - 2];
		for (ll i = 0; i < N-2-i; i++) {
			ok &= (v[i] + v[N - 2 - i] == sum);
			if (!ok) break;
		}
		if (ok) return v[0] + v[N - 2] - v[N - 1];
	}
	ll ans = 0;
	ll sum = v[0] + v[N - 1];
	ll i = 0, j = N - 1;
	while (i <= j) {
		if (v[i] + v[j] != sum) {
			if (ans > 0) {
				ans = -1;
				break;
			}
			if (v[i] + v[j] > sum) {
				ans = sum - v[j];
				j--;
			} else {
				ans = sum - v[i];
				i++;
			}
		} else {
			i++;
			j--;
		}
	}
	if (ans > 0) return ans;

	i = 1, j = N - 1;
	sum = v[1] + v[N - 1];
	while (i < j && v[i] + v[j] == sum) {
		i++;
		j--;
	}
	if (i >= j && sum - v[0] > 0) return sum - v[0];
	
	return -1;
}

int main (void) 
{
	// freopen("C_sample_in.txt", "r", stdin);
	// freopen("C_sample_out.txt", "w", stdout);
	// freopen("C_test_in.txt", "r", stdin);
	// freopen("C_test_out.txt", "w", stdout);
	freopen("C_in.txt", "r", stdin);
	freopen("C_out.txt", "w", stdout);
	ll T;
	cin >> T;

	for (ll C = 1; C <= T; C++)
	{
		cout << "Case #" << C << ": ";
		cout << solve() << "\n";	
	}	
	return (0);
}

/**
 * By Lorenzo Fiorini
 * 
 * Contact
 * 	- linkedin.com/in/lorenfiorini/
 *	- github.com/LorenFiorini
*/ 

