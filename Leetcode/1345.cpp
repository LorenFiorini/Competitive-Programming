class Solution {
public:
    int minJumps(vector<int>& arr) {
        // num -> indexes
        int n = arr.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);

        vector<int> dis(n, 1e9);
        queue<int> Q;
        Q.push(0);
        dis[0] = 0;


        while (!Q.empty()) {
            queue<int> q;

            while (!Q.empty()) {
                int i = Q.front();
                Q.pop();

                for (auto nxt: mp[arr[i]]) {
                    if (dis[nxt] > dis[i] + 1) {
                        dis[nxt] = dis[i] + 1;
                        q.push(nxt);
                    }
                }
                mp.erase(arr[i]);

                if (i + 1 < n && dis[i + 1] > dis[i] + 1) {
                    dis[i + 1] = dis[i] + 1;
                    q.push(i + 1);
                }
                if (i > 0 && dis[i - 1] > dis[i] + 1) {
                    dis[i - 1] = dis[i] + 1;
                    q.push(i - 1);
                }
                
            }
            swap(q, Q);
        }
        return dis[n-1];
    }
};
