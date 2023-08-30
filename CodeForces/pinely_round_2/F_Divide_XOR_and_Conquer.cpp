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

void solve(void) {
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		showbin(a[i], 5);
	}
	
	// Prefix 
	// vector<long long> b(n);

	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t; while (t--)
	solve();
	
	return 0;
}

// Lorenzo Fiorini

/*

*/