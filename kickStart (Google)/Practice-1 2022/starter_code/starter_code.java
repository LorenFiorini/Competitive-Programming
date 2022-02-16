import java.util.Scanner;

/** Starter code for the Kick Start 2022 problem Hex. */
public class HexStarterCode {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    // Read the number of test cases.
    int t = scanner.nextInt();
    for (int caseIndex = 1; caseIndex <= t; caseIndex++) {
      // Read the board size.
      int n = scanner.nextInt();
      // Read each row of the board.
      char[][] board = new char[n][];
      for (int i = 0; i < n; i++) {
        board[i] = scanner.next().toCharArray();
      }
      // Determine the game status and display it.
      String status = determineStatus(board);
      System.out.println("Case #" + caseIndex + ": " + status);
    }
  }

  /** Returns a status string as specified by the Hex problem statement. */
  static String determineStatus(char[][] board) {
    // TODO(you): Implement this method to solve the problem!
    return "";
  }
}
