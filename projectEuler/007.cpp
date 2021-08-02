#include <bits/stdc++.h>
using namespace std;

int main ()
{
	vector<int> v;
	int num = 2;
	int n = v.size();
	while (n != 10001) {
		bool init = false;
		for (int i = 0; i < n; i++) {
			if (num % v[i] == 0) {
				init = true;
				break;
			}
		}
		if (!init) {
			v.push_back(num);
		}
		num++;
		n = v.size();
	}
	cout << v[1e4];
	return 0;
}
