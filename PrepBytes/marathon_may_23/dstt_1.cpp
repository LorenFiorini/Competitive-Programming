/* Problem */

/*
Do Solve This Task

Statement
Alice is given an integer sequence of N numbers from his teacher as an assignment. There may be duplicate numbers in sequence. He will remove some of the numbers from this sequence, which on multiplying with another number present in this sequence result in a cube.
Find the maximum length of a good sequence after removing some integers. A good sequence is a sequence in which no two elements have their procut as a cubic number.
For eg: If sequence is as 1,2,3,4 then 2 and 4 on multiplying make 8 so we have to either remove 2 or 4 so, final sequence will be 1,2,3 on multiplying any 2 resultant will never be a cubic number.


Input format
Input file contains a single integer N followed by a sequence of N integers. The ith element of the sequence is represented by S_i.


Output format
Print the maximum length of the good integer sequence.


Constraints
1 <= N <= 10^5
1 <= S_i <= 10^10
All input values are integers.


Time Limit
2 second


Examples:
Sample Input 1
8
1
2
3
4
5
6
7
8

Sample Output 1
6

Sample Input 2
6
2
4
8
16
32
64

Sample Output 2
3

Explanation for sample input 1: 
Good sequence with maximum length will be 1,2,3,5,6,7.

*/


/* Solution */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mx_val = 1e10;

set<ll> cubes (void)
{
    set<ll> st;
    for (ll i = 2; ; i++)
    {
        ll cube = i * i * i;
        if (cube > mx_val)
            break;
        st.insert(cube);
    }
    return st;
}

// Return true if num is the cube of an integer
bool is_cube(ll num)
{
    ll lo = 1, hi = 1e5;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll cube = mid * mid * mid;
        if (cube == num)
            return true;
        else if (cube < num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}

int main (void)
{
    ll N;
    cin >> N;
    vector<ll> v(N);
    for (ll i = 0; i < N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    set<ll> st = cubes();
    set<ll> S;

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {

        bool ok = true;
        for (ll num: S) {
            //ok &= (st.find(num * v[i]) == st.end());
            ok &= (!is_cube(num * v[i]));
            if (!ok)
                break;
        }
        if (ok) {
            //cout << v[i] << "\n"; // debug
            S.insert(v[i]);
            ans++;
        }

    }

    cout << ans << endl;
    return (0);
}

// Lorenzo Fiorini

