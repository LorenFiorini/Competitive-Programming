#include<bits/stdc++.h>
using namespace std;

void left(vector<int> &v) {
	int i = 0;
	while (v[i]) {
		i++;
	}
	v[i] = 1;
}

void right(vector<int> &v) {
	int i = 9;
	while (v[i]) {
		i--;
	}
	v[i] = 1;
}


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(10, 0);
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			left(v);
		} else if (s[i] == 'R') {
			right(v);
		} else {
			v[s[i] - '0'] = 0;
		}
	}
	
	for (int i = 0; i < 10; i++) cout << v[i];
	cout << endl;
}
