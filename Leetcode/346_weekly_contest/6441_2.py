class Solution {
    int sum_dig(int num) {
        int c = 0;
        while (num > 0) {
            c += num % 10;
            num /= 10;
        }
        int ans = c;
        if (c > 9) {
            ans = sum_dig(c);
        }
        return ans;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int num = 1; num <= n; num++) {
            int t = sum_dig(num);
            if (t == 1 || t == 9) {
                cout << num << endl;
                ans += (num * num);
            }
        }
        cout << "\n";
        return ans;
    }
};