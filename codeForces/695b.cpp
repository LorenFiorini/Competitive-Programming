#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    string ans = "987654321";
    string san = "0123456789";
    int j = 0;
    int n;
    cin >> n;
    string answer;
    if (n <= 10) {
        while (n-- && j < 9) {
            answer.push_back(ans[j]);
            j++;
        }
        if (j == 9) answer.push_back('0');
    } else {
        cout << ans;
        n -= 9;
        while (n > 0) {
            if (n >= 10) {
                answer += san;
                n -= 10;
            } else {
                while (n--) {
                    answer.push_back(san[j]);
                    j++;
                }
            }
        }
    }
    /*
    FOR(i,0,n) {
        if (i < 10){
            answer.push_back(ans[j]);
        } else {
            answer.push_back(san[j]);
        }
    if (i == 9) j = 0; 
        j++;
        j %= 10;
    }
    */
    cout << answer <<"\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name