/** Problem Statement
 A. Secret Sport
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Let's consider a game in which two players, A and B, participate. This game is characterized by two positive integers, 𝑋
 and 𝑌
.

The game consists of sets, and each set consists of plays. In each play, exactly one of the players, either A or B, wins. A set ends when one of the players reaches 𝑋
 wins in the plays of that set. This player is declared the winner of the set. The players play sets until one of them reaches 𝑌
 wins in the sets. After that, the game ends, and this player is declared the winner of the entire game.

You have just watched a game but didn't notice who was declared the winner. You remember that during the game, 𝑛
 plays were played, and you know which player won each play. However, you do not know the values of 𝑋
 and 𝑌
. Based on the available information, determine who won the entire game — A or B. If there is not enough information to determine the winner, you should also report it.

Input
Each test contains multiple test cases. The first line contains a single integer 𝑡
 (1≤𝑡≤104)
 - the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤20)
 - the number of plays played during the game.

The second line of each test case contains a string 𝑠
 of length 𝑛
, consisting of characters 𝙰
 and 𝙱
. If 𝑠𝑖=𝙰
, it means that player A won the 𝑖
-th play. If 𝑠𝑖=𝙱
, it means that player B won the 𝑖
-th play.

It is guaranteed that the given sequence of plays corresponds to at least one valid game scenario, for some values of 𝑋
 and 𝑌
.

Output
For each test case, output:

𝙰
 — if player A is guaranteed to be the winner of the game.
𝙱
 — if player B is guaranteed to be the winner of the game.
?
 — if it is impossible to determine the winner of the game.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
typedef int64_t ll;

// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";


void solve () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	show(s[n-1]);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */
