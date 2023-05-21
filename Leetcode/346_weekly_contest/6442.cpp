class Solution {
    void debug(vector<int>& v_) {
        for (auto a_: v_) {
            cout << a_ << " ";
        }
        cout << "\n";
    }
    void debugg(vector<vector<int>>& mat_) {
        for (auto v_: mat_) {
            for (auto a_: v_) {
                cout << a_ << " ";
            }
            cout << "\n";
        }
    }
    void debuggg(vector<vector<vector<int>>>& A) {
        for (auto mat_: A) {
            debugg(mat_);
            cout << "\n";
        }
    }
    
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int S, int T, int target) {
        vector<vector<int>> adj(n, vector<int> (n, 1e9));
        vector<vector<vector<int>>> A(n);
        
        for (auto &e: edges) {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
            A[e[0]].push_back({e[1], e[2]});
            A[e[1]].push_back({e[0], e[2]});
        }
        //cout << "Adj\n";     debugg(adj);
        //cout << "A\n";        debuggg(A);
        
        
        
        return {};
    }
};