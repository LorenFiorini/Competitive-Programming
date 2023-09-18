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


int get_msb (int x) {
	int msb = 0;
	while (x > 0) {
		x >>= 1;
		msb++;
	}
	return msb;
}

void solve (void) {
	vector<int> ans(2, 0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m + 1, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];
	
	int msb_a = get_msb(*max_element(a.begin(), a.end()));
	int msb_b = get_msb(*max_element(b.begin(), b.end()));
	int msb = max(msb_a, msb_b);
	int limit_num = (1 << msb) - 1;
	// show(limit_num);

	vector<int> cnt_bit(msb, 0);
	int xor_a = 0;
	for (int i = 0; i < n; i++) {
		xor_a ^= a[i];
		for (int j = 0; j < msb; j++) {
			if (a[i] & (1 << j)) cnt_bit[j]++;
		}
	}
	// showv(cnt_bit);

	if (n % 2 == 1) {
		int num = xor_a
		for (int j = 0; j < msb; j++) {
			if (cnt_bit[j] % 2 == 1) num |= (1 << j);
		}
		ans[0] = xor_a;
		ans[1] = xor_a;
	} else {
		int num = 0;
		for (int j = 0; j < msb; j++) {
			if (cnt_bit[j] % 2 == 1) num |= (1 << j);
		}
		ans[0] = num;
		ans[1] = num ^ xor_a;
	}
	showv(ans);
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
 * By Lorenzo Fiorini
 * 
 * Contact
 * 	- linkedin.com/in/lorenfiorini/
 *	- github.com/LorenFiorini
*/ 

