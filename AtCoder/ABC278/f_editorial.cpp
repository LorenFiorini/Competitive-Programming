#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main() {
    using namespace std;

    unsigned N;
    cin >> N;

    // the first and last character of the i-th string
    vector<pair<unsigned char, unsigned char>> info(N);
    for (auto&&[first, last] : info) {
        string S;
        cin >> S;
        first = S.front() - 'a';
        last = S.back() - 'a';
    }

    // the c-th significant bit of dp[S] = whether the first player wins when unused words are S and the last character is c
    vector<unsigned> dp(1UL << N);
    for (unsigned S{3}; S < 1UL << N; ++S) {
        for (unsigned c{}; c < N; ++c) {
            //cout << S << " " << c << endl;
            if (1 & S >> c)
            dp[S] |= (1UL & ~dp[S ^ 1UL << c] >> info[c].second) << info[c].first;
        }
    }

    // if any bit of dp[2^N - 1] is set, then the first player wins
    cout << (dp.back() ? "First" : "Second") << endl;

    return 0;
}
