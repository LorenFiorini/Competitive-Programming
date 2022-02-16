#include <bits/stdc++.h>
using namespace std;

string FindBoardStatus(int size, char* board) {
  // TODO: Complete this function to find the status of the board.

  return "";
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    int n;
    cin >> n;
    char board[100][100];
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        cin >> board[r][c];
      }
    }
    cout << "Case #" << tc << ": " << FindBoardStatus(n, board) << endl;
  }
  return 0;
}
