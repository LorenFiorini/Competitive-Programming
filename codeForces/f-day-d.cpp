#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	set<int> st;
	set<int>:: iterator it;
	string ans = "YES";
	while (n > 0) {
		int num;
		if (n < m) num = n;
		else num = n % m;
		it = st.find(num);
		if (it == st.end()) {
			st.insert(num);
		} else {
			ans = "NO";
		}
		n /= m;
	}
	
	cout << ans;
	return 0;
}
