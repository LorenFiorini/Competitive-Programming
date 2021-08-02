#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// -------------------------------------
	int N;
	int K;
	cin >> K >> N;	
	vector <string> names(N);
	map <string, int> mp;
	map <string, int> :: iterator it;
	for (int i = 0; i < N ; i++) {
		string str;
		cin >> str;
		names[i] = str;
		mp[str] = 0;
	}
	// -------------------------------------
	
	while (K--)
	{
		vector<int> maximum(N);
		vector<int> minimum(N);
		vector<string> researchers(N);
		//    input names
		for (int i = 0; i < N ; i++) 
		{
			cin >> researchers[i];
			minimum[i] = i;
			maximum[i] = i;
			if (i && researchers[i - 1] < researchers[i]) {
				minimum[i] = minimum[i - 1];
			}
		}
		// set upper bound
		for (int i = N; i > 0 ; i--) 
		{
			if (minimum[i - 1] == minimum[i]) 
				maximum[i - 1] = maximum[i];
		}
		// sum average
		for (int i = 0; i < N ; i++)
		{
			int average = (maximum[i] + minimum[i]) / 2;
			mp[researchers[i]] += minimum[i];
		}
	}
	for (int i = 0; i < N ; i++) 
	{
		for (int j = 0; j < N ; j++) 
		{
			if (i == j) 
			{
				cout << "B";
				continue;
			}
			if (mp[names[i]] < mp[names[j]]) 
				cout << "0";
			else if (mp[names[i]] > mp[names[j]]) 
				cout << "1";
			else 
				cout << "?";
		}
		cout << endl;
	}
	return 0;
}


