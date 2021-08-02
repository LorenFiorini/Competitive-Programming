#include <bits/stdc++.h>
using namespace std;

int main(){
	int period = 0;
	int number = 0;
	for (int i = 2; i < 1000; i++) {
		vector<int> v;
		vector<int>::iterator it;
		int a = 10;
		while (a != 0) {
			int rem = a % i;
			it = find(v.begin(), v.end(), rem);
			if (it != v.end()) {
				if (v.end() - it > period) {
					period = v.end() - it;
					number = i;
				}
				break;
			} else {
				v.push_back(rem);
			}
			a = 10 * rem;
		}
	}
	cout << number;
	return 0;	
}
