/*
You are given a string s and an integer k.

A k-subsequence is a subsequence of s, having length k, and all its characters are unique, i.e., every character occurs once.

Let f(c) denote the number of times the character c occurs in s.

The beauty of a k-subsequence is the sum of f(c) for every character c in the k-subsequence.

For example, consider s = "abbbdd" and k = 2:

f('a') = 1, f('b') = 3, f('d') = 2
Some k-subsequences of s are:
"abbbdd" -> "ab" having a beauty of f('a') + f('b') = 4
"abbbdd" -> "ad" having a beauty of f('a') + f('d') = 3
"abbbdd" -> "bd" having a beauty of f('b') + f('d') = 5
Return an integer denoting the number of k-subsequences whose beauty is the maximum among all k-subsequences. Since the answer may be too large, return it modulo 109 + 7.

A subsequence of a string is a new string formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.

Notes

f(c) is the number of times a character c occurs in s, not a k-subsequence.
Two k-subsequences are considered different if one is formed by an index that is not present in the other. So, two k-subsequences may form the same string.
*/

/*
Example 1:

Input: s = "bcca", k = 2
Output: 4
Explanation: From s we have f('a') = 1, f('b') = 1, and f('c') = 2.
The k-subsequences of s are: 
bcca having a beauty of f('b') + f('c') = 3 
bcca having a beauty of f('b') + f('c') = 3 
bcca having a beauty of f('b') + f('a') = 2 
bcca having a beauty of f('c') + f('a') = 3
bcca having a beauty of f('c') + f('a') = 3 
There are 4 k-subsequences that have the maximum beauty, 3. 
Hence, the answer is 4. 
Example 2:

Input: s = "abbcd", k = 4
Output: 2
Explanation: From s we have f('a') = 1, f('b') = 2, f('c') = 1, and f('d') = 1. 
The k-subsequences of s are: 
abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5
abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5 
There are 2 k-subsequences that have the maximum beauty, 5. 
Hence, the answer is 2. 
 

Constraints:

1 <= s.length <= 2 * 105
1 <= k <= s.length
s consists only of lowercase English letters.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
	long long mod = 1e9 + 7;
	long long choose(long long n, long long k) {
		if (k > n) return 0;
		if (k * 2 > n) k = n - k;
		if (k == 0) return 1;

		long long result = n;
		for (long long i = 2; i <= k; ++i) {
			result *= (n - i + 1);
			result /= i;
		}
		return result;
	}
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if (k >= 26) return 0LL;
        vector<long long> beauty(26);
		for (char c: s) beauty[c - 'a']++;
        
		long long ans = 1, sum = 0;
		sort(beauty.begin(), beauty.end(), greater<long long>());
		long long cnt = 0, before_k = 0;
		for (int i = 0; i < 26; i++) {
			if (i < k) {
				if (beauty[i] == 0) return 0LL;
				sum += beauty[i];
				if (beauty[i] != beauty[k - 1])
					ans = (ans * beauty[i]) % mod;
				else {
					cnt++;
					before_k++;
				}
			} else {
				if (beauty[i] == beauty[k - 1]) {
					cnt++;
				} else {
					break;
				}
			}
		}
		cout << "cnt: " << cnt << endl;
		cout << "ans: " << ans << endl;
		if (cnt <= before_k) return ans;
		
		long long comb = choose(cnt, cnt - before_k);
		ans = (ans * comb) % mod;
		return ans;
    }
};


int main(void) {
	Solution sol;
	
	string s1 = "bcca";
	cout << sol.countKSubsequencesWithMaxBeauty(s1, 2) << endl;

	string s2 = "abbcd";
	cout << sol.countKSubsequencesWithMaxBeauty(s2, 4) << endl;

	string s3 = "abcde";
	cout << sol.countKSubsequencesWithMaxBeauty(s3, 5) << endl;

	string s4 = "e";
	cout << sol.countKSubsequencesWithMaxBeauty(s4, 1) << endl;

	string s5 = "lelxul";
	cout << sol.countKSubsequencesWithMaxBeauty(s5, 1) << endl;
	return 0;
}

/**
 * Input
"bcca"
2
"abbcd"
4
"lelxul"
1
*/