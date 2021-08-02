#include <bits/stdc++.h>
using namespace std;

int main () 
{
	int n, k;
	cin >> k >> n;	
	vector<string> vec(n);
	map<string, int> mp;
	map<string, int>::iterator it;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vec[i] = str;
		mp[str] = 0;
	}
	//
	while (k-- > 0)
	{
		vector<int> pnt(n);
		vector<string> tmpp(n);
		
		for (int i = 0; i < n ; i++) 
		{
			cin >> tmpp[i];
			pnt[i] = i;
			if (i && tmpp[i - 1] < tmpp[i]) {
				pnt[i] = pnt[i - 1];
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			mp[tmpp[i]] += pnt[i];
		}
	}
	//
	vector<string> mat(n);
	for (int i = 0; i < n ; i++) 
	{
		string li;
		for (int j = 0; j < n ; j++) 
		{
			if (i == j) {
				li += 'B';				
			}
			else if (mp[vec[i]] > mp[vec[j]]) {
				li += '1';
			}
			else if (mp[vec[i]] < mp[vec[j]]) {
				li += '0';
			} else
			li += '?';
		}
		mat[i] = li;
	}
	//
	for (int i = 0; i < n; i++) {
		cout << mat[i] << endl;
	}
}


