/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.
*/
/*
bool ifPossible(vector<int> nums, int k, int mid){
        long long int cSum = 0;
        for(int i = 0; i<mid; i++){
            cSum+=nums[i];
        }
        int l = 0;
        int i = mid;

        int t = (cSum+k)/mid;
        if(t>=nums[i-1]) return true;
        while(i<nums.size()){
            cSum+=nums[i];
            cSum-=nums[l];
            l++;
            i++;
            int t = (cSum+k)/mid;
            if(t>=nums[i-1]) return true;
        }
        return false;

    }*/
class Solution {
    bool possible(vector<int>& nums, int k, int mid, int n) {
        long long int sum = 0;
        for (int i = 0; i < mid; i++) {
            sum += nums[i];
        }
        int l = 0;
        int r = mid;

        do {
            sum += nums[r];
            sum -= nums[l];
            r++;
            l++;
            int t = (sum + k) / mid;
            if (t >= nums[r - 1])
                return true;
        } while (r < n);
        return false;
    
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while (l <= r) {
            int mid = (l+r+1)/2;
            if (possible(nums, k, mid, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};