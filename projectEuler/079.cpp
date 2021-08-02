#include <bits/stdc++.h>
using namespace std;

void show(set<int> st) {
	for (auto x : st) {
		cout << x << endl;
	}	
}

int main () {	
	ifstream f("079_keylogs.txt");
	set<int> st;
	string s;
	while (getline(f, s)) {
		int num = stoi(s);
		st.insert(num);
	}
	f.close();
	show(st);
	cout << "\n\n";

	set<int> ma;
	set<int> mb;
	set<int> mc;
	for (auto it = st.begin(); it != st.end(); it++) {
		int a = *it / 100;
		int b = (*it % 100) / 10;
		int c = *it % 10;
		ma.insert(a);
		mb.insert(b);
		mc.insert(c);
		
		
		if (a != 7 && a != 3) {
			cout << a;
		} else {
			cout << "-";
		}
		if (b != 3 && b != 9) {
			cout << b;
		} else {
			cout << "-";
		}
		if (c != 9 && c != 0) {
			cout << c;
		} else {
			cout << "-";
		}
		cout << "\n";
	}
	cout << "\n\n";
	cout << "----------\n"; 
	show(ma);
	cout << "----------\n"; 
	show(mb);
	cout << "----------\n"; 
	show(mc);
	
	
	return 0;
}
// 73162890
/*
 * 1-  7
 * 2-  3
 * 
 * ------> 1 2 6 8
 * 1
 * 6
 * 2
 * 8
 * 9-  9
 * 10- 0
 * 
 * D - 
 */
