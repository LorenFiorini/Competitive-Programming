#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--) 
	{
		int n;
		string ans = "YES";
		cin >> n;
		string s;
		cin >> s;
		vector<char> u; 
		u.push_back(s[0]);
		for (int i = 1; i < n ; i++) {
			if (s[i-1] == s[i]) continue;
			u.push_back(s[i]);
		}
		set<char> st;
		set<char>:: iterator it ;
		for (int i = 0; i < (int) u.size(); i++) {
			it = st.find(u[i]);
			if (it == st.end()) st.insert(u[i]);
			else ans = "NO";
		}
		cout << ans << "\n";
		
	}
}
