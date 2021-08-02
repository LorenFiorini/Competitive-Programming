#include <bits/stdc++.h>
using namespace std;

bool pal (int num) {
	string str = to_string(num);
	for (int i = 0; i < 3; i++) {
		if (str[i] != str[5-i]) {
			return false;
		}
	}
	return true;
}


int main() 
{
	priority_queue<int> q;
	for (int i = 999; i >= 100; i--) {
		for (int j = 999; j >= 100; j--) {
			int tmp = i * j;
			if (pal(tmp)) {
				q.push(tmp);
			}
		}
	}
	cout << q.top();
	return 0;
}
