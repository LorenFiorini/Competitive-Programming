#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long answer = 0;
	long long n, l;
	cin >> n >> l;
	vector<long long> v(n);
	for (long long i = 0; i < n; i++) cin >> v[i];
	
	long long fir = 0;
	sort(v.begin(), v.end(), greater<> ());
	for (long long i = 0; i < n; i++) 
	{
		if (i > 0 && v[i-1] > v[i]) fir = i;
		long long len = i - fir + 1;
		
		long long index = min(v[i], i + 1);
		if (v[i] < i + 1 && len <= l){
			index = v[i] + 1;
		}
		answer = max(answer, index);
	}
	cout << answer;
	return 0;
}

