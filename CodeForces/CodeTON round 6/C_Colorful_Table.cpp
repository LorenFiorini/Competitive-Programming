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

vector<vector<int>> help(vector<int> &a, int n) {
	// Number -> {left, right}
	vector<vector<int>> v;
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		if (mp.find(a[i]) == mp.end()) {
			mp[a[i]] = {i, i};
		} else {
			mp[a[i]][1] = i;
		}
	}

	auto rit = mp.rbegin();
	int l = rit->second[0], r = rit->second[0];
	while (rit != mp.rend()) {
		int le = rit->second[0], ri = rit->second[1];
		rit->second[0] = min(l, le);
		rit->second[1] = max(r, ri);
		l = rit->second[0], r = rit->second[1];			
		rit++;
	}
	for (auto p: mp) {
		v.push_back({p.first, p.second[0], p.second[1]});
	}
	return v;
}

void solve (void) {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> v = help(a, n);
	int sz = v.size();
	int i = 0;
	for (int c = 1; c <= k; c++) {
		// while (i < sz && v[i][0] > c) i++;
		if (i < sz && v[i][0] == c) {
			int ans = (v[i][2] - v[i][1] + 1) * 2;
			cout << ans << " ";
			i++;
		} else {
			cout << 0 << " ";
		}	
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
 * By Lorenzo Fiorini
 * 
 * Contact
 * 	- linkedin.com/in/lorenfiorini/
 *	- github.com/LorenFiorini
*/ 

