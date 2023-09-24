#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t, n, u, v;
class Node{
    public:
        int weight;
        Node* parent;
        vector<Node*> children;
        Node(Node* par) : parent(par) {}
        void add(Node* child) {
            children.push_back(child);
        }
};

void solve () {
    vector<<vector<int>> vec(n+1, vector<int> (1));
    FOR(i, 1, n+1) {
        cin >> vec[i][0];
    }
    FOR(i, 0, n-1) {
        cin >> u >> v;
        vec[v].push_back(vec[u]);
    }
    int ans;

    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name