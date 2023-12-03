
/**You are given a string word and an integer k.

A substring s of word is complete if:

Each character in s occurs exactly k times.
The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.
Return the number of complete substrings of word.

A substring is a non-empty contiguous sequence of characters in a string.
*/

// #define show(VAR) cout << VAR << endl;
// #define showv(CON) for(auto VAR : CON) cout << VAR << " "; cout << endl;


// class Solution {
// public:
//     int countCompleteSubstrings(string word, int k) {
//         int N = word.size();
//         int ans = 0;

//         // Count the frequency of each character
//         vector<vector<int>> freq(N, vector<int> (26, 0));
//         for (int i = 0; i < N; i++) {
//             freq[i][word[i] - 'a']++;
//             if (i > 0) {
//                 for (int j = 0; j < 26; j++) {
//                     freq[i][j] += freq[i - 1][j];
//                 }
//             }
//         }
        
//         for (int i = 0; i < N; i++) {
//             int count_starting_here = 0;
//             for (int j = i + k; j < N; j += k) {
//                 bool flag = true;
//                 for (int l = 0; l < 26; l++) {
//                     int f = freq[j][l] - (i > 0 ? freq[i - 1][l] : 0);
//                     if (f != 0 && f != k) {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if (flag) count_starting_here++;
//             }
//             ans += count_starting_here * (count_starting_here + 1) / 2;
//         }

//         return ans;
//     }
// };



#define show(VAR) cout << VAR << endl;
#define showv(CON) for(auto VAR : CON) cout << VAR << " "; cout << endl;


class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int N = word.size();
        int ans = 0;

        vector<int> v;
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
        for (int i = 0; i <= N; i++) {showv(freq[i]); cout << endl;}
        
        v.push_back(N);
        int len = v.size();
        int idx = 0;
        for (int i = 0; i <= N; i++) {
            if (idx < len && i == v[idx]) {
                freq[i] = vector<int> (26, 0);
                idx++;
            }
            for (int j = i + k; j <= v[idx]; j += k) {
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
                    cout << i << " " << j << " -> " << word.substr(i, j - i) << endl;

                    ans++;
                }
            }
        }

        return ans;
    }
};