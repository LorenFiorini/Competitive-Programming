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
	int ans = 0;
	long long a, b, c;
	
	
	cout << ans << endl;
}

int main (void) 
{
	freopen("A2_sample_in.txt", "r", stdin);
	freopen("A2_sample_out.txt", "w", stdout);
	freopen("A2_test_in.txt", "r", stdin);
	freopen("A2_test_out.txt", "w", stdout);
	freopen("A2_in.txt", "r", stdin);
	freopen("A2_out.txt", "w", stdout);

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

/*

*/