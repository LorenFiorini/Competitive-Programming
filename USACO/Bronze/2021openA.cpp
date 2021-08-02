#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, L, H = 0;
	cin >> n >> L;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int> ());
	for (int i = 0, j = 0; i < n; i++) 
	{
		if (i > 0 && arr[i-1] > arr[i]) 
			j = i;
		bool ok = (i - j + 1) <= L;
		int idx = min(arr[i], i + 1);
		if (arr[i] < i + 1 && ok){
			idx = arr[i] + 1;
		}
		
		H = max(H, idx);
	}
	cout << H << endl;
}

