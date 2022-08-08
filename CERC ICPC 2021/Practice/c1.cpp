#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define each(it, mp) for(auto it = mp.begin(); it != mp.end(); i++)

const bool cmp(pii const  &a, pii const &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.second;
}

struct myComp {
    constexpr bool operator()(const pii &a, const pii &b) {
        if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.second;
    }
};

void showpq(priority_queue<pii, vector<pii>, myComp> pq) {
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		cout << p.first << " " << p.second << "\n";
	}
	cout << "----\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	priority_queue<pii, vector<pii>, myComp> pq;
	ll mx_t = 0;
	rep(i,0,n) {
		cin >> v[i];
		mx_t += (ll) v[i] / 100;
		if (v[i] % 100 == 0) mx_t--;
		pq.push(make_pair(v[i], i));
	}
	
	// impossible
	if (mx_t < (ll) k) {
		cout << "impossible\n";
		return 0;
	}
	
	
	showpq(pq);
	rep (theft, 0, k) {
		pii p = pq.top();
		pq.pop();
		
		pq.push(make_pair(p.first - 100, p.second));
		
		showpq(pq);
	}
	
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		v[p.second] = p.first;
	}
	
	for (int num : v) {
		cout << num << " ";
	}
	cout << "\n";
	
	
	return 0;
}
