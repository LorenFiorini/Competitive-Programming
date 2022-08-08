#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define each(it, mp) for(auto it = mp.begin(); it != mp.end(); it++)



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	// money -> poeple
	map<int, int> mp;
	ll mx_t = 0;
	rep(i,0,n) {
		cin >> v[i];
		mx_t += (ll) (v[i] / 100);
		if ((v[i] % 100) == 0) mx_t--;
		mp[v[i]]++;
	}
	
	// impossible
	if (mx_t < (ll) k) {
		cout << "impossible\n";
		return 0;
	}
	
	while (k > 0) {
		auto it = mp.rbegin();
		int money = it->first;
		int peo = it->second;
		if (k >= peo) {
			mp.erase(money);
			mp[money - 100] += peo;
			k -= peo;
		} else {
			mp[money - 100] += k;
			mp[money] -= k;
			k = 0;
		}
	}
	
	// remainder -> numbers
	map<int, queue<int>> rem;
	each(it, mp) {
		int id = (it->first) % 100;
		rep(i, 0, it->second){
			rem[id].push(it->first);
		}		
	}
	
	rep(i ,0, n) {
		int id = v[i] % 100;
		
		v[i] = rem[id].front();
		rem[id].pop();
		if (rem[id].empty()) rem.erase(id);
	}
	
	rep(i, 0, n) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
