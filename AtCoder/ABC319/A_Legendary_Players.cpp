/*A - Legendary Players / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100 points

Problem Statement
In AtCoder, the top 
10 rated players' usernames are displayed with a gold crown, and the top-rated player's username is displayed with a platinum crown.

At the start of this contest, the usernames and ratings of the top 
10 rated players in the algorithm category are as follows:

Copy
tourist 3858
ksun48 3679
Benq 3658
Um_nik 3648
apiad 3638
Stonefeang 3630
ecnerwala 3613
mnbvmar 3555
newbiedmy 3516
semiexp 3481tourist 3858
ksun48 3679
Benq 3658
Um_nik 3648
apiad 3638
Stonefeang 3630
ecnerwala 3613
mnbvmar 3555
newbiedmy 3516
semiexp 3481
You are given the username 
S of one of these players. Print that player's rating.

Constraints
S is equal to one of the usernames of the top 
10 rated players in the algorithm category.
Input
The input is given from Standard Input in the following format:

S
Output
Print the rating of the corresponding player in one line.
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

int main() {
  string s;
  cin >> s;
  if (s == "tourist") {
	cout << 3858 << endl;
  } else if (s == "ksun48") {
	cout << 3679 << endl;
  } else if (s == "Benq") {
	cout << 3658 << endl;
  } else if (s == "Um_nik") {
	cout << 3648 << endl;
  } else if (s == "apiad") {
	cout << 3638 << endl;
  } else if (s == "Stonefeang") {
	cout << 3630 << endl;
  } else if (s == "ecnerwala") {
	cout << 3613 << endl;
  } else if (s == "mnbvmar") {
	cout << 3555 << endl;
  } else if (s == "newbiedmy") {
	cout << 3516 << endl;
  } else if (s == "semiexp") {
	cout << 3481 << endl;
  }
  return 0;
}

/* Lorenzo Fiorini */
