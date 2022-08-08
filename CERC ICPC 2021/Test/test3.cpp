#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define each(it, mp) for(auto it = mp.begin(); it != mp.end(); it++)

struct Pair {
	int x;
	int y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &a : v) cin >> a;
	
	cout << n << "\n";
	for (int i = n-1; i >= 0; i--) cout << v[i] << "\n";
	
	return 0;
}
