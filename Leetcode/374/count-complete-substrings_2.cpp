
#define show(VAR) cout << VAR << endl;
#define showv(CON) for(auto VAR : CON) cout << VAR << " "; cout << endl;


class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int N = word.size();
        int ans = 0;

        vector<int> v(1, 0);
        // Count the frequency of each character
        vector<vector<int>> freq(N + 1, vector<int> (26, 0));
        for (int i = 0; i < N; i++) {
            freq[i + 1][word[i] - 'a']++;
            if (i > 0 && abs(word[i] - word[i - 1]) > 2) {
                v.push_back(i);
                continue;
            }
            for (int j = 0; j < 26; j++) {
                freq[i + 1][j] += freq[i][j];
            }
        }
        // for (int i = 0; i <= N; i++) {showv(freq[i]); cout << endl;}
        
        v.push_back(N);
        int len = v.size();
        int idx = 0;
        for (int i = 0; i < N; i++) {
            if (idx < len && i == v[idx]) {
                freq[i] = vector<int> (26, 0);
                idx++;
            }
            for (int j = i + k; j < v[idx]; j += k) {
                int flag = 0;
                for (int l = 0; l < 26; l++) {
                    int f = freq[j][l] - freq[i][l];
                    if (f == k) {
                        flag += 1;
                    } else if (f != 0) {
                        flag = -1;
                        break;
                    }
                }
                if (flag > 0) {
                    // cout << i << " " << j << " -> " << word.substr(i, j - i) << endl;

                    ans++;
                }
            }
        }

        return ans;
    }
};