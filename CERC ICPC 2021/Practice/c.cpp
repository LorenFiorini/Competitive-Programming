#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define each(it, mp) for(auto it = mp.begin(); it != mp.end(); i++)



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	// money -> index
	map<int, vector<int>> mp;
	ll mx_t = 0;
	rep(i,0,n) {
		cin >> v[i];
		mx_t += (ll) v[i] / 100;
		if (v[i] % 100 == 0) mx_t--;
		mp[v[i]].push_back(i);
	}
	
	// impossible
	if (mx_t < (ll) k) {
		cout << "impossible\n";
		return 0;
	}
	
	rep (theft, 0, k) {
		auto it = mp.rend();
		
		int sz = it->second.size()
		if (k - theft >= sz) {
			it->first -= 100;
		}
		
		int val = it->first - 100;
		int pos = it->second[0];
		
		it->second.pop();
		if (it->second.empty()) mp.erase(it);
		
		mp[val].push_back(pos);
	}
	
	return 0;
}
