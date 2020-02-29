#include <stdio.h>
#include <stdlib.h>

int main() {
  char board[8][8];
  board[0] = {".", ".", ".", ".", ".", ".", ".", "."};
  board[1] = {".", ".", ".", "p", ".", ".", ".", "."};
  board[2] = {".", ".", ".", "R", ".", ".", ".", "p"};
  board[3] = {".", ".", ".", ".", ".", ".", ".", "."};
  board[4] = {".", ".", ".", ".", ".", ".", ".", "."};
  board[5] = {".", ".", ".", "p", ".", ".", ".", "."};
  board[6] = {".", ".", ".", ".", ".", ".", ".", "."};
  board[7] = {".", ".", ".", ".", ".", ".", ".", "."};
  int i, j;
  int count = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (board[i][j] == 'R') {
        goto ROOK;
      }
    }
  }
// Found the location of Rook
ROOK:
  // check same row first
  // count = isPawnBefore(board[i][j]) + isPawnAfter(board[i][j]);
  printf("%d,%d\n", i, j);
  return 0;
}
