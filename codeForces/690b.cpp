#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int t, n;
string s;

void solve () {
    string year = "2020";
    vector<string> my;
    FOR(i, 0, n) {
        if (s[i] == '2'){
            string temp = "2";
            FOR(j,1,4){
                if(s[i+j] == year[j])
                    temp += year[j];
                else {
                    i+=(j-1);
                    break;
                }
            }
            my.push_back(temp);
        }
    }
    FOR(i,1,my.size()){
        string tmp = my[i-1] + my[i];
        FOR (j,0,4){
            if(tmp[j] == year[j]){
                if (j==3) {
                    cout << "YES"<< "\n";
                    return;
                }
            } else break;
        }
    }
    cout << "NO" << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name