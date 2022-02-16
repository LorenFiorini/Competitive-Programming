def game_status(number_of_days, vistors):
  # TODO: implement this method to determine the status of the game board
  return ""

def main():
  test_cases = int(raw_input())
  for test_case in range(1, test_cases + 1, 1):
    board_size = int(raw_input())
    board = []
    for _ in range(board_size):
      board.append(list(raw_input().strip()))

    ans = game_status(board_size, board)

    print("Case #{}: {}".format(test_case, ans))

if __name__ == "__main__":
  main()
