// Final

typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n = nums.size(), ans = 0, mn, mx, le;
        mn = mx = le = n;

        for (ll i = 0; i < n; i++) {
            if (minK <= nums[i] && nums[i] <= maxK) {
                le = min(le, i);
                if (nums[i] == minK) mn = i;
                if (nums[i] == maxK) mx = i;
                if (max(mx, mn) < n) {
                    ll ri = min(mn, mx);
                    ans += ri - le + 1;
                }
            } else {
                mn = mx = le = n;
            }
        }

        return ans;
    }
};









// First

typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        if (maxK < minK) return (0);
        ll ans = 0;
        int n = nums.size();
        // Last minimum value index
        int mn = n, mx = n;

        for (int i = 0; i < n; i++) {
            // Update indexes
            if (nums[i] < minK || maxK < nums[i]) {
                mn = mx = n;
            } else if (nums[i] == minK) {
                mn = i;
            } else if (nums[i] == maxK) {
                mx = i;
            }
            // Compute subarrays from j = min(mn, mx) until ith
            if (minK <= nums[i] && nums[i] <= maxK && max(mx, mn) < n) {
                ll len = i - min(mx, mn) + 1;
                cout << len << endl;
    
            }
        }

        return ans;
    }
};

/*
nums[i] <   minK
        =   minK
        >   minK && < maxK
        =   maxK
        >   maxK

*/


// Second

typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        if (maxK < minK) return (0);
        ll ans = 0;
        int n = nums.size();
        // 1. // Last minimum value index
        // 1. int mn = n, mx = n;
        vector<int> mins, maxs;
        int mn = 0, mx = 0, from = n;

        for (int i = 0; i < n; i++) {
            // Update indexes
            if (nums[i] < minK || maxK < nums[i]) {
                // 1. mn = mx = n;
                mins.clear();
                maxs.clear();
                mn = mx = 0;
                from = n;
            } else if (nums[i] == minK) {
                // 1. mn = i;
                mins.push_back(i);
                mn++;
            } else if (nums[i] == maxK) {
                // 1. mx = i;
                maxs.push_back(i);
                mx++;
            }

            if (minK <= nums[i] && nums[i] <= maxK) {
                from = min(from, i);
                if (min(mx, mn) > 0) {
                    //ll le = max(mins[0], maxs[0]);
                    ll le = from;
                    ll ri = min(mins[mn - 1], maxs[mx - 1]);

                    cout << le << " " << ri << endl;
                    ans += ri - le + 1;
                }
            }
            /*
            if (minK <= nums[i] && nums[i] <= maxK) {
                int id = mins.size() - 1;
                int jd = maxs.size() - 1;

                while (min(id, jd) > 0) {
                    ll le = min(mins[id], maxs[jd]);
                    ll ri = max(mins[id], maxs[jd]);
                    ll cnt = 0;

                    if (mins[id] > maxs[jd]) {

                        id--;
                    } else {

                        jd--;
                    }
                }
            }
            
            // Compute subarrays from j = min(mn, mx) until ith
            if (minK <= nums[i] && nums[i] <= maxK && max(mx, mn) < n) {
                // 1. ll len = i - min(mx, mn) + 1;
                // 1. cout << len << endl;
                
            }
            */
        }

        return ans;
    }
};

/*
nums[i] <   minK
        =   minK
        >   minK && < maxK
        =   maxK
        >   maxK

*/



// Third - It works

typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        if (maxK < minK) return (0);
        vector<int> mins, maxs;
        int n = nums.size();
        ll ans = 0;
        int mn = 0, mx = 0, from = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] == minK) {
                mins.push_back(i);
                mn++;
            }
            if (nums[i] == maxK) {
                maxs.push_back(i);
                mx++;
            }


            if (minK <= nums[i] && nums[i] <= maxK) {
                from = min(from, i);
                if (min(mx, mn) > 0) {
                    ll le = from;
                    ll ri = min(mins[mn - 1], maxs[mx - 1]);
                    ll len = ri - le + 1;

                    //cout << le << " " << ri << ": " << len << endl;
                    ans += len;
                }
            } else {
                mins.clear();
                maxs.clear();
                mn = mx = 0;
                from = n;
            }
        }

        return ans;
    }
};

