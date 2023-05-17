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
#define showbin(X_) for (int I = (1 << 30); I > 0; I >>= 1) {cout << ((X_&I)? 1: 0);} cout << "\n";
#define showp(X_, Y_) cout << X_ << " " << Y_ << "\n";
#define showv(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define showvp(V_) for (auto P_: V_) {showp(P_.first, P_.second);}
#define showmat(MAT) for (auto R_: MAT) {showv(R_);}
#define showset(ST) for (auto X_: ST) {cout << X_ << " ";} cout << "\n";
#define showmap(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";

/* Problem: Kth Prime Sum

We are given Q queires of the form (L, R, K).
For each query you are asked to print the Kth smallest number in the range L to R (both inclusively)
whose digit sum is a prime number or report (print -1) if it doesn't exist.


Input Format

• First line of input contains an integer Q. 
• Next Q lines contain three space-separated integers L R K denoting the query.


Output Format

For each query, print a single integer denoting the answer to the ith query.


Constraints

1 <= Q <= 500
1 <= L <= R <= 10^18
1 <= K <= R - L + 1


SAMPLE INPUT

5
3 7 2
6 6 1
10 100 15
10 1000 115
10 10000 1115

SAMPLE OUTPUT

5
-1
43
319
3358

*/

// Solution Code

set<ll> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

ll digit_sum(ll n) {
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

//string find_min_digit_sum(string lstr, string rstr) {}

void query(void) {
	ll ans = -1;
	ll left, right, k;
	cin >> left >> right >> k;

    for (ll num = left; num <= right; num++) {
        ll dig = digit_sum(num);
        cout << num << " " << dig << "\n";
        if (primes.find(dig) != primes.end()) {
            k--;
            if (k == 0) {
                ans = num;
                break;
            }
        }
    }
/*
    ll l = digit_sum(left);
    ll r = digit_sum(right);
	ans = primes.size();
    
    // Find maximum and minimum digit sum in range
    string lstr = to_string(left);
    string rstr = to_string(right);

    ll min_id = find_min_digit_sum(lstr, rstr);
    ll max_id = find_max_digit_sum(lstr, rstr);
*/
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q; cin >> q; while (q--)
	
	query();
	
	return 0;
}

// Lorenzo Fiorini

/*

1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 1
11 2
12 3
13 4
14 5
15 6
16 7
17 8
18 9
19 10
20 2
21 3
22 4
23 5
24 6
25 7
26 8
27 9
28 10
29 11
30 3
31 4
32 5
33 6
34 7
35 8
36 9
37 10
38 11
39 12
40 4
41 5
42 6
43 7
44 8
45 9
46 10
47 11
48 12
49 13
50 5
51 6
52 7
53 8
54 9
55 10
56 11
57 12
58 13
59 14
60 6
61 7
62 8
63 9
64 10
65 11
66 12
67 13
68 14
69 15
70 7
71 8
72 9
73 10
74 11
75 12
76 13
77 14
78 15
79 16
80 8
81 9
82 10
83 11
84 12
85 13
86 14
87 15
88 16
89 17
90 9
91 10
92 11
93 12
94 13
95 14
96 15
97 16
98 17
99 18
100 1
-1


*/