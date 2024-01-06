
/**You are given a string word and an integer k.

A substring s of word is complete if:

Each character in s occurs exactly k times.
The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.
Return the number of complete substrings of word.

A substring is a non-empty contiguous sequence of characters in a string.
*/

#define show(VAR) cout << VAR << endl;
#define showv(CON) for(auto VAR : CON) cout << VAR << " "; cout << endl;


class Solution {
    bool check(vector<int>& freq, int k) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0 && freq[i] != k) {
                return false;
            }
        }
        return true;
    }
public:
    int countCompleteSubstrings(string word, int k) {
        int N = word.size();
        int ans = 0;

        // Count the frequency of each character
        vector<int> freq(26, 0);
        
        // Two pointers approach
        // The inner while goes until for two adjacent characters, the difference is more than 2
        int l = 0, r = 0;
        while (r < N) {
            while ((r < N - 1 && abs(word[r] - word[r + 1]) <= 2) || r == N-1) {
                freq[word[r] - 'a']++;
                if (freq[word[r] - 'a'] == k) {
                    ans += check(freq, k);
                } else if (freq[word[r] - 'a'] > k) {
                    while (l < r && freq[word[r] - 'a'] > k) {
                        freq[word[l] - 'a']--;
                        l++;
                    }
                    ans += check(freq, k);
                }
                r++;
            }
            while (l < r) {
                freq[word[l] - 'a']--;
                ans += check(freq, k);
                l++;
            }
        }

        return ans;
    }
};