#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <fcntl.h>

#ifdef DEBUG
#include <chrono>
#endif

using namespace std;

int main(int argc, char const *argv[]) {
	#ifdef DEBUG
	using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::microseconds;

	auto t1 = high_resolution_clock::now();
	#endif

	(void)argc;

	ifstream inputFile	(argv[1], O_RDONLY);

	int m = -1, ans = 0;
	int row = 0, col = 0;
	int i = 0, j = 0;
	string tmp;
	vector<vector<int>> dp;
	
	while (getline(inputFile, tmp)) {
		if (m == -1) {
			m = tmp.size();
			dp.resize(2, vector<int> (m, 0));
		}
		for (j = 0; j < m; j++) {
			if (tmp[j] == '.') {
				dp[i % 2][j] = 1;
				if (i > 0 && j > 0)
                    dp[i % 2][j] += min(dp[(i-1) % 2][j-1], min(dp[i % 2][j-1], dp[(i-1) % 2][j]));
				if (dp[i % 2][j] > ans) {
					ans = dp[i % 2][j];
					col = j, row = i;
				}
			} else {
				dp[i % 2][j] = 0;
			}
		}
		i++;
	}
	cout << row - ans + (ans > 0) << "," << col - ans + (ans > 0) << "|" << row << "," << col << endl;

	#ifdef DEBUG
	auto t2 = high_resolution_clock::now();
	auto us_int = duration_cast<microseconds>(t2 - t1);
	cout << us_int.count() << "us" <<endl;
	#endif
	return 0;
}
