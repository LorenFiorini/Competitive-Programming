/* Problem */

/*
Seat Arrangement

Statement
Prepbudy is hosting a function in an auditorium that contains a row of R seats. The people coming to the function are either couples or single.
You are given an N size array containing 1 or 2. Where 1 indicate single people and 2 indicate couple.
Each couple and single person will randomly choose unoccupied chairs where all couples can sit consecutively, and occupy those chairs. However, if there are not enough consecutive unoccupied chairs, they will leave without taking seats.
Determine whether it is guaranteed that all N groups(both single and couple) can take seats.

Input format
The first line contains a single integer N and R the number of groups and the number of seats in the row.
The next line contains N space-separated integers a_1, a_2, . . ., a_N.

Output format
If it is guaranteed that all N groups can take seats, print "Yes"; otherwise, print "No".

Constraints
1 <= N <= 10^5
1 <= a_i <= 2
L = a_1 + a_2 + . . . + a_N

Time Limit
1 second

Example
Input 
2 42 2

Output
No

Explanation
Let us number the chairs 1,2,3,4 from left to right. If the first couple takes chairs for 2 and 3, the next couple cannot take seats and will leave. Thus, it is not guaranteed that all N groups can take seats, so you should print "No".
*/


/* Solution */

#include <bits/stdc++.h>
using namespace std;

void solve () {
    // Input
	int N, R;
	cin >> N >> R;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

    // Solution
    int free_seats = R;
    int free_consecutive = R;
    for (int i = 0; i < N; i++) {
        free_seats -= a[i];
        if (free_seats < 0 || (a[i] == 2 && free_consecutive < 2)) {
            cout << "No" << endl;
            return;
        }
        free_consecutive -= a[i] + 1;
    }


    cout << "Yes" << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

// Lorenzo Fiorini

