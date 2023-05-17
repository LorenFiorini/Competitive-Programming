#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
#define por(i_, a_, b_, in_) for (int i_ = a_; i < (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v_.size()
#define precision(d_) cout << setprecision(d_) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

// Problem

/*
Problem
You are preparing for meals ahead of your busy night at Restaurant Deep Dishes. An essential ingredient is apples.

In your inventory, you have M kilograms of crushed apples. Head Chef Sandeep needs exactly N kilograms of crushed apples, but Chef Pal has lost the weighing machine. Instead, all that is left is a balance pan with two scales. You do not have any measuring weights with you either.

So you can only place some crushed apples on both sides of the balance, and the balance will tell you whether or not they are of equal weight. You don't get any more information from it.
And peculiarly, it gives out an error if both sides are not integers. You don't know if they are equal or not in this case.

In other words, this is what you can do:

You can take a known weight of apples and divide into two equal parts using the balance, if the two halves have integer weights.
You can take crushed apples of a known integer weight and get another portion of crushed apples that weighs the same, using the balance.
And of course, even without using the balance, you can combine together known weights to get a heavier known weight.
Chef Pal is asking for your help. Under these constraints, is it possible to get exactly N kilograms of crushed apples? Note that when you start out, the only weight that you know is that the entire crushed apples weights M kilograms.
*/

/*
Input Format
The first line of the input contains one integer T, the number of test cases. The test cases follow.
The only line of each testcase contains two integers M and N, the kilograms of apples you have, and the kilograms of apples that you need to make, respectively.

Output Format
For each test case, if it is possible to use the balance scale to get exactly N kilograms from M kilograms, output YES.
If it is not possible, output NO.
Note: You can output the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will be recognized as positive responses.
*/

/*
1. If M < N, then it is impossible to get N kilograms from M kilograms.
2. If M = N, then it is possible to get N kilograms from M kilograms.
3. If M > N, then it is possible to get N kilograms from M kilograms if and only if M - N is even.

*/


bool dfs(set<pll> &memo, vll& vec, ll i, ll sum, ll n, ll N) {
	if (sum == n) return true;
	if (sum > n || i == N) return false;

	if (memo.find(mk(i, sum)) != memo.end()) {
		return false;
	}
	memo.insert(mk(i, sum));

	// with current element
	if (dfs(memo, vec, i+1, sum + vec[i], n, N)) return 1;
	// without current element
	if (dfs(memo, vec, i+1, sum, n, N)) return 1;
	
	return 0;
}

bool fun(ll m, ll n) {
	set<pll> memo;
	vll vec;

	vec.pb(m);
	while (m % 2 == 0 && m > 0) {
		m /= 2;
		vec.pb(m);
	}

	return dfs(memo, vec, 0, 0, n, vec.size());
}

void solve () {
	ll ans = 0;
	ll m, n;
	cin >> m >> n;
	
	if (m >= n) {
		ans = fun(m, n);
	}
	
	
	if (ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
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
void solve () {
	ll ans = 0;
	ll m, n;
	cin >> m >> n;
	
	if (m == n) {
		ans = 1;
	} else if (m > n) {
		set<ll> st;
		
		//ll x = m;
		st.insert(m);
		while (m % 2 == 0 && m > 0) {
			m /= 2;
			st.insert(m);
			//x |= m;
		}
		while (m <= n) {
			m *= 2;
			st.insert(m);
			//x |= m;
		}
		
		ll val = 0;
		for (ll num: st) {
			if (num & n) {
				val |= num;
			}
		}

		ans = (val == n);
	}
	
	
	if (ans == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
*/