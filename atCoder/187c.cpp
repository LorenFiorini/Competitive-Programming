#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    int n;
    cin >> n;
    vector<string> v(n);
    set<string> z;
    set<string>::iterator it;
    set<string>::iterator it2;
    FOR (i, 0,  n) {
        cin >> v[i];
        /*
        if (v[i][0] == '!') {
            it2 = z.find(v[i]);
            v[i].erase(0, 1);
        }*/
        //cout << v[i] << "  ";
        z.insert(v[i]); 
    }
    FOR (i, 0, n) {
        if (v[i][0] != '!') {
            it = z.find(v[i]);
            string str = "!";
            str += v[i];
            it2 = z.find(str);
            if (it != z.end() && it2 != z.end()) {
                cout << v[i];
                return;
            }
        }
    }
    cout << "satisfiable";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    solve();
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name