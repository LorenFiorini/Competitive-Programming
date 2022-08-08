#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define each(it, mp) for(auto it = mp.begin(); it != mp.end(); i++)



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	set<map<char, int>> st;
	
	vector<string> ans;
	rep (T, 0, n) {
		string t;
		cin >> t;
		
		map<char, int> mp;
		for (char c : t) mp[c]++;
		
		if (st.find(mp) == st.end()) {
			st.insert(mp);
			ans.push_back(t);
		}
	}
	
	for (string str: ans) {
		cout << str << "\n";
	}
	
	return 0;
}
