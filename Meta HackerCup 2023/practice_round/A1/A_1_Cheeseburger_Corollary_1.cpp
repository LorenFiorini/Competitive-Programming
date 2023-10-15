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


string solve (void) {
	long long ans = 0;
	long long s, d, k;
	cin >> s >> d >> k;
	
	ll buns = 2 * s + 2 * d;
	ll cheese = s + 2 * d;
	if (buns <= k || cheese < k) return "NO";

	return "YES";
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
This problem shares some similarities with A2, with key differences in bold.
Problem solving skills are applicable to many daily musings. For instance, you might ponder over shared birthdays, bird houses, mapmaking, or ordering an exact number of chicken nuggets. Naturally, another great question to ponder is: how many deckers of a cheeseburger you could build if you spent your entire salary on fast food!
Specifically, you're interested in building a 
�
K-decker cheeseburger, which alternates between buns, cheese, and patty starting and ending with a bun. You've already bought 
�
S single cheeseburgers and 
�
D double cheeseburgers. Each provides you with two buns, though a single provides one patty and one cheese, while a double provides two patties and two cheese.

You'd like to know whether you can build a 
�
K-decker cheeseburger with the ingredients from 
�
S single and 
�
D double cheeseburgers.
Constraints
1
≤
�
≤
4
0
1≤T≤40
0
≤
�
,
�
≤
1
0
0
0≤S,D≤100
1
≤
�
≤
1
0
0
1≤K≤100
Input Format
Input begins with an integer 
�
T, the number of test cases. Each case contains one line with three space-separated integers, 
�
S and 
�
D and 
�
K.
Output Format
For the 
�
ith test case, print "Case #i: " followed by "YES" if you have enough ingredients to build a 
�
K-decker cheeseburger, or "NO" otherwise.
Sample Explanation
In the first case, you have one single and one double cheeseburger. In total, you have 
4
4 buns, 
3
3 slices of cheese, and 
3
3 patties. This gives you exactly enough ingredients to build a 
3
3-decker cheeseburger.
In the second case, you have 
4
4 buns, but a 
4
4-decker cheeseburger would require 
5
5, so you cannot build it.
In the third case, you have plenty of ingredients to build a 
1
1-decker cheeseburger. You'll even have 
4
4 single and 
5
5 double cheeseburgers left over afterwards.

Sample Input
7
1 1 3
0 2 4
5 5 1
0 1 1
1 1 2
97 1 99
97 1 100

Sample Output
Case #1: YES
Case #2: NO
Case #3: YES
Case #4: YES
Case #5: YES
Case #6: YES
Case #7: NO
*/

