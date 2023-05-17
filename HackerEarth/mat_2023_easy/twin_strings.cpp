#include "bits/stdc++.h"
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
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
#define por(I_, A_, B_, in__) for (int I_ = A_; I_ < (B_); I_ += in__)
#define rep(I_, A_, B_) por(I_, A_, B_, 1)
#define each(it, MP) for (auto it = MP.begin(); it != MP.end(); it++)
#define all(C_) C_.begin(), C_.end()
#define allg(C_) all(C_), greater<> ()
#define len(V_) (int) V_.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(X_) cout << X_ << "\n";
#define showbin(X_, K_) for (int I = (1 << K_); I > 0; I >>= 1) {cout << ((X_&I)? 1: 0);} cout << "\n";
#define showp(X_, Y_) cout << X_ << " " << Y_ << "\n";
#define showv(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define showvp(V_) for (auto P_: V_) {showp(P_.first, P_.second);}
#define showmat(MAT) for (auto R_: MAT) {showv(R_);}
#define showset(ST) for (auto X_: ST) {cout << X_ << " ";} cout << "\n";
#define showmap(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";

// Problem Statement
/*
Twin Strings

Max. score: 100

You are given a string S of length N. A string is called twin if the characters of the string can be split into two groups such that the occurrence of each character is equal in both groups.

Find the number of twin substrings of S.

Input Format:

• The first line contains an integer T, denoting the number of test cases. 
• The first line of each test case contains an integer N, denoting the length of the string S.
• The second line of each test case contains the string S.

Output Format:

For each test case, print the number of twin substrings of S.

Constraints:

1<=T<=10

1<=N<=10^5

S contains lower-case English letters

SAMPLE INPUT
2
6
abccba
4
abdd

SAMPLE OUTPUT
3
1

*/

// Solution

vint binary_char(string s, int n) {
    vint b(n);
    rep(i, 0, n) {
        int shift = s[i] - 'a';
        b[i] = 1 << shift;
    }
    return b;
}

void solve (void) {
	int ans = 0;
	int n;
	cin >> n;
	string s;
	cin >> s;
    vint bi = binary_char(s, n);

    //rep(i, 0, n) {
    //    cout << s[i] << ": ";
    //    showbin(bi[i], 8);
    //}
    map<int, int> mp;
    int x = 0;
    mp[0] = 1;
    rep(i, 0, n) {
        x = x ^ bi[i];
        mp[x]++;
    }

    for (auto p: mp) {
        if (p.second > 1) {
            ans += p.second * (p.second - 1) / 2;
            //ans += p.second;
        }
    }
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
