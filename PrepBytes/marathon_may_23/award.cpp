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

long long mod = 1000000007;

int main () 
{
    // Input
    long long N;
	cin >> N;

    long long ans = 0;

    // DP
    long long dp[N+1][3][4];
    memset(dp, 0, sizeof(dp));

    
    for (int j = 0; j <= 2; j++) 
        for (int k = 0; k <= 3; k++)
            dp[0][j][k] = 1;

    for (int i = 1; i <= N; i++) 
    {
        // If we have a C
        for (int j = 0; j <= 2; j++) 
        {
            for (int k = 0; k <= 3; k++) 
            {
                if (j == 2)
                    dp[i][j][k] = dp[i-1][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j+1][k];
                dp[i][j][k] %= mod;
            }
        }

        // If we have a B
        for (int j = 0; j <= 2; j++) 
        {
            for (int k = 0; k <= 3; k++) 
            {
                if (j == 2)
                    dp[i][j][k] += dp[i-1][j-1][k];
                else
                    dp[i][j][k] += dp[i-1][j+1][k];
                dp[i][j][k] %= mod;
            }
        }

        // If we have an A
        for (int j = 0; j <= 2; j++) 
        {
            for (int k = 0; k <= 3; k++) 
            {
                if (k == 3)
                    dp[i][j][k] += dp[i-1][j][k];
                else
                    dp[i][j][k] += dp[i-1][j][k+1];
                dp[i][j][k] %= mod;
            }
        }

        // Modulo
        //for (int j = 0; j <= 2; j++) 
        //{
        //    for (int k = 0; k <= 3; k++) 
        //    {
        //        dp[i][j][k] %= mod;
        //    }
        //}
    }

    // Output
    for (int j = 0; j <= 2; j++) 
    {
        for (int k = 0; k <= 3; k++) 
        {
            ans += dp[N][j][k];
            ans %= mod;
        }
    }

    cout << ans << endl;

    // Debug DP
    for (int i = 0; i <= N; i++) 
    {
        for (int j = 0; j <= 2; j++) 
        {
            for (int k = 0; k <= 3; k++) 
            {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

	return (0);
}

// Lorenzo Fiorini

