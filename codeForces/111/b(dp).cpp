#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
 
int solve(int i, int j, vector<vector<int>> &dp, string &s){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 1+solve(i+1, j, dp, s);
    for(int k=i+1; k<=j; k++){
        if(s[i]==s[k]){
            int a = solve(i+1, k-1, dp, s);
            int b = solve(k, j, dp, s);
            ans = min(ans, a+b);
        }
    } 
    return dp[i][j] = ans;
}
 
int main()
{
	//
	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if(b<0){
            vector<vector<int>> dp(n, vector<int>(n, -1));
            int mi = solve(0, n-1, dp, s);
            int ans = n*a + b*mi;
            cout << ans << endl;
        }
        else{
            cout << n*(b+a) << endl;
        }
    }
   //
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms";
    return 0;
    //
}
