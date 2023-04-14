typedef long long ll;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll n = time.size();
        ll start = 0, end = 1e14;

        while (start <= end) {
            ll mid = (end - start) / 2 + start;
            ll trip = 0;

            for (ll i = 0; i < n; i++) {
                trip += mid / time[i];
            }
            if (trip < totalTrips) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start;
    }
};