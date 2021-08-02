#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int le(int m) {
    int digits = 0;
    while (m > 0) {
        m /= 10;
        digits++;
    }
    return digits;
}

void solve () {
    ll n, m;
    cin >> n >> m;
    //Vectors
    int p = 0;
    vector<int> v(n + 1, 0); v[p] = 1;
    vector<int> res;
    int mL = le(m);
    //      DIVISION
    while (1) 
    {
        // tmp = vector num
        int tmp = v[p];
        while (tmp < m) {
            if (p == n) break;
            p++;
            tmp *= 10;
            tmp += v[p];
        }
        //cout << tmp;
        //take remainder(to V) and 
        int rem = tmp % m;// cout << rem << "  ";
        int remL = le(rem);
        FOR (i, 0, remL) {
            int lastnum = rem % 10;
            v[p] = lastnum;
            if (i != remL - 1) p--; //to dont overflow nor move one extra
            rem /= 10; 
        }
        //result(vector RES)
        int result = tmp / m;
        stack<int> stck;
        while (result > 0) { 
            stck.push(result % 10);
            result /= 10;
        }
        while (!stck.empty()) {
            int numhere = stck.top();
            res.push_back(numhere);
            stck.pop();
        }
        //
        if (p == n) break;
    }
    int nn = res.size();
    p = 0;
    int RA;
    // DIVISION TAKING REMAINDER (result vector / m)
    while (1) 
    {
        // tmp = vector result
        int tmp = res[p];
        while (tmp < m) {
            if (p == nn - 1) break;
            p++;
            tmp *= 10;
            tmp += res[p];
        }
        //cout << tmp;
        //take remainder(to V) and 
        int rem = tmp % m; //cout << rem << "  ";
        RA = rem;
        int remL = le(rem);
        FOR (i, 0, remL) {
            int lastnum = rem % 10;
            res[p] = lastnum;
            if (i != remL - 1) p--; //to dont overflow nor move one extra
            rem /= 10; 
        }
        /*
        //result(vector RES)
        int result = tmp / m;
        stack<int> stck;
        while (result > 0) { 
            stck.push(result % 10);
            result /= 10;
        }
        while (!stck.empty()) {
            int numhere = stck.top();
            res.push_back(numhere);
            stck.pop();
        }
        // */
        if (p == nn - 1) break;
    }

    cout << RA << "\n";
      
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name