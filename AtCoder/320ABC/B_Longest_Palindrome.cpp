#include<bits/stdc++.h>
using namespace std;

int get_odd_lenght_palindrome (string s, int i) {
	int ans = 1;
	int n = s.size();
	int l = i - 1;
	int r = i + 1;
	while (l >= 0 && r < n && s[l] == s[r]) {
		ans += 2;
		l--;
		r++;
	}
	return ans;
}

int get_even_lenght_palindrome (string s, int i) {
	int ans = 0;
	int n = s.size();
	int l = i;
	int r = i + 1;
	while (l >= 0 && r < n && s[l] == s[r]) {
		ans += 2;
		l--;
		r++;
	}
	return ans;
}

void solve () {
	int ans = 0;
	string s;
	cin >> s;
	int n = s.size();

	// Find longest palindrome substring starting at index i
	for (int i = 0; i < n; i++) {
		int odd_lenght_palindrome = get_odd_lenght_palindrome(s, i);
		int even_lenght_palindrome = get_even_lenght_palindrome(s, i);
		ans = max(ans, max(odd_lenght_palindrome, even_lenght_palindrome));
	}
	cout << ans << endl;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */

/*
Problem Statement
You are given a string 
S. Find the maximum length of a contiguous substring of 
S that is a palindrome.
Note that there is always a contiguous substring of 
S that is a palindrome.

Constraints
S is a string of length between 
2 and 
100, inclusive, consisting of uppercase English letters.
*/
