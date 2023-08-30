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
	int ans = 0;
	int n, m, k;
	cin >> n >> m >> k;

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
G. Swaps
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array of integers a1,a2,…,an
 (1≤ai≤n
). You can perform the following operation several (possibly, zero) times:

pick an arbitrary i
 and perform swap(ai,aai)
.
How many distinct arrays is it possible to attain? Output the answer modulo (109+7)
.

Input
The first line contains an integer n
 (1≤n≤106
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
).

Output
Output the number of attainable arrays modulo (109+7)
.
*/