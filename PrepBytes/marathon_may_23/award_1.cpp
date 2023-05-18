/* Problem */

/*
Officer of The Year Award

Statement
Wonderland Army Institute has decided to give the Officer of the year award to the most consistent officer in the institute. The performance record for an officer can be represented as a string where each character signifies the level of performance of the officer on that day.

The performance record contains following 3 characters:
′C′: Officer was not present on the training ground.
′B′: Officer was present in the training ground but left after the interval.
′A′: Officer completed full training that day.

Any officer is eligible for the award if they meet both of the following criteria:
1. The officer was absent (′C′) for strictly fewer than 2 days total.
2. The officer never left the training ground after the interval (′B′) for 3 or more consecutive days.

The Director of the institute wants to know the number of possible attendance records of length N that make an officer eligible for the award.

The answer may be very large, so print it modulo 1000000007.


Input format
Input contains an integer N. The length of performance record.


Output format
The number of possible performance records of length N that make an officer eligible for the award.
Note - The answer may be very large, so print it modulo 1000000007.


Constraints
1 <= N <= 10^5


Time Limit
1 second


Examples:
Sample Input 1
2

Sample Output 1
8

Sample Input 2
500

Sample Output 2
757982199

Explanation for sample input 1: 
There are 8 records with length 2 that are eligible for an award:
"AA", "CA", "AC", "BA", "AB", "CB", "BC", "BB".
Only "CC" is not eligible.
*/


/* Solution */

#include <bits/stdc++.h>
using namespace std;

typedef int ll;
ll mod = 1000000007;

// ll dp[A][B][C][consecutive_b];
//ll dp[100002][66700][2][3];
//ll dp[1002][667][2][3];
ll dp[100002][2][3];

ll dfs(ll a, ll b, ll c, ll consecutive_b, ll N) {
    if (consecutive_b >= 3 || c >= 2) return 0;
    if (N == 0) return 1;
    if (dp[a+b][c][consecutive_b] != -1)
        return dp[a+b][c][consecutive_b];
    
    ll ans = 0;
    // A
    ans = (ans + dfs(a+1, b, c, 0, N-1)) % mod;

    // B
    ans = (ans + dfs(a, b+1, c, consecutive_b+1, N-1)) % mod;

    // C
    ans = (ans + dfs(a, b, c+1, 0, N-1)) % mod;

    dp[a+b][c][consecutive_b] = ans;
    return ans;
}

int main () 
{
    // Input
    ll N;
	cin >> N;

    // Solution
    memset(dp, -1, sizeof(dp));
    ll a = 0, b = 0, c = 0;
    ll ans = dfs(a, b, c, 0, N);

    // Output
    cout << ans << endl;

    // Debug DP
    /*
    int n = N+1;
    for (int i = 0; i < n; i++) {
        //cout << "i=" << i << " ";
        for (int j = 0; j < n; j++) {
            //cout << "j=" << j << " ";
            for (int k = 0; k < 2; k++) {
                //cout << "k=" << k << " ";
                for (int l = 0; l < 3; l++) {
                    //cout << "l=" << l << endl;
                    cout << dp[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << "---\n" << endl;
    }
    */
	return (0);
}

// Lorenzo Fiorini

/*
Choose a character. Until you got N. There are 3 choices. 

// We can choose between 0 and N times the character 'A'
A: [0, N]

// We can choose between 0 and N*2/3 times the character 'B'
B: [0, N*2/3]
i.e. floor(N*2/3) = N*2/3

// We can choose between 0 and 1 times the character 'C'
C: [0, 1]
inclusive


DP[i][j][k]
    A   B   C
    ABC ABC AB

*/