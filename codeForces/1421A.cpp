#include<bits/stdc++.h>
using namespace std;


int main() {
int T; cin >> T;
while (T--)
	{
		int a, b;
		cin >> a >> b;
		int x = a & b;
		cout << ((x^a) + (x^b)) << "\n";
	}
	return 0;
}
