#include <iostream>
using namespace std;

class Sudoku {
  private:
    int grid[9][9];

  public:
    Sudoku(int inputGrid[9][9]) {
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          grid[i][j] = inputGrid[i][j];
        }
      }
    }

    void display() const {
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          cout << grid[i][j] << " \n"[j == 8];
        }
      }
    }

    friend bool solveSudoku(Sudoku &sudoku, int row, int col);

  private:
    bool isSafe(int row, int col, int num) const {
      /* ??? */

      cout << "in issafe" << endl;
      // checking in row
      for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) {
          return false;
        }
      }

      // checking in column
      for (int y = 0; y < 9; y++) {
        if (grid[y][col] == num) {
          return false;
        }
      }

      // checking in box
      int startR;
      int startC;

      if ((0 <= row) && (row <= 2)) { startR = 0; }
      else if (row <= 5) { startR = 3; }
      else if (row <= 8) { startR = 6; }

      if ((0 <= col) && (col <= 2)) { startC = 0; }
      else if (col <= 5) { startC = 3; }
      else if (col <= 8) { startC = 6; }

      int startRcopy = startR + 2;
      cout << "startR: " << startR << endl;
      cout << "startRcopy: " << startRcopy << endl;

      int startCcopy = startC + 2;
      cout << "startC: " << startC << endl;
      cout << "startCcopy: " << startCcopy << endl;

      for (; startR <= startRcopy; startR++) {
        for (; startC <= startCcopy; startC++) {
          if (grid[startR][startC] == num) {
            return false;
          }
        }
      }

      return true;
    }
};

bool solveSudoku(Sudoku &sudoku, int row, int col) {
  /* ??? */
  for (int num = 1; num <= 9; num++) {
    cout << "in first for loop" << endl;
    if ((sudoku.grid[row][col] == 0) && (sudoku.isSafe(row, col, num) == true)) { // first check if it is safe
      sudoku.grid[row][col] = num; // then assign it
      cout << "in line 77" << endl;
    } else if (sudoku.grid[row][col] != 0) {
      if (row == 8 && col != 8) {
        solveSudoku(sudoku, row, col + 1);
      } else if (row != 8 && col == 8) {
        solveSudoku(sudoku, row + 1, col);
      } else if (row == 8 && col == 8) {
        return false;
      }
    }

    if (num == 9 && sudoku.grid[row][col] == 0) {
      if (row == 8 && col != 8) {
        solveSudoku(sudoku, row, col + 1);
      } else if (row != 8 && col == 8) {
        solveSudoku(sudoku, row + 1, col);
      } else if (row == 8 && col == 8) {
        for (int outerCount = 0; outerCount < 9; outerCount++) {
          for (int innerCount = 0; innerCount < 9; innerCount++) {
            if (sudoku.grid[outerCount][innerCount] == 0) {
              solveSudoku(sudoku, outerCount, innerCount);
            } else {
              continue;
            }
          }
        }
      }
    }
  }

  return true;
}

int main() {
  int puzzle[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
  };

  Sudoku sudoku(puzzle);
  cout << "Original Sudoku:\n";
  sudoku.display();

  if (solveSudoku(sudoku, 0, 0)) {
    cout << "\nSolved Sudoku:\n";
    sudoku.display();
  } else {
    cout << "\nNo solution exists.\n";
  }

  return 0;
}
