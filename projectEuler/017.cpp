#include <bits/stdc++.h>
using namespace std;

int main() 
{
	map <int, int> mp;
	map <int, int>::iterator it;
	mp[0] = 0;
	mp[1] = 3;
	mp[2] = 3;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 4;
	mp[6] = 3;
	mp[7] = 5;
	mp[8] = 5;
	mp[9] = 4;
	mp[14] = 8;
	mp[16] = 7;
	mp[17] = 9;
	mp[19] = 8;
	//
	mp[10] = 3;
	mp[20] = 6;
	mp[30] = 6;
	mp[40] = 5;
	mp[50] = 5;
	mp[60] = 5;
	mp[70] = 7;
	mp[80] = 6;
	mp[90] = 6;
	mp[1000] = 11;
	for (int num = 1; num <= 1000; num++) {
		it = mp.find(num);
		if (it == mp.end()) {
			mp[num] = 0;
			// 100
			if (num / 100 > 0) {
				int dig = num / 100;
				mp[num] = mp.at(dig) + 7;
			} 
			// 10
			if (num % 100 > 0) {
				if (mp[num] > 0) mp[num] += 3;
				int dd = num % 100;
				it = mp.find(dd);
				if (it != mp.end()) {
					// when num >= 100
					mp[num] += mp.at(dd);
				}
				if (dd == num){
					// when num < 100
					mp[num] = mp.at(num) + mp.at((dd/10) * 10);
					mp[num] = mp.at(num) + mp.at(dd%10);
				}
			}			
		} 
	}
	
	int answer = 0;	
	for (it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << "   " << it->second << "\n" ;	
		answer += it->second;
	}
	cout << answer;
	
	return 0;
}
