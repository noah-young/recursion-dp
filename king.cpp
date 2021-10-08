/*
 * Program that takes the dimensions of a chess board from the 
 * user and determines the number of paths a king can take from
 * the first file to the last.
 *
 * Author: Noah Young
 */

#include <iostream>

using namespace std;

unsigned long long paths(int r, int c);

int main() {
  // user inputs number of rows and columns in the chess board.
  cout << "Enter board dimensions for the king's path: ";
  int row_count, col_count;
  cin >> row_count >> col_count;

  // output the number of paths the king can take
  cout << "Paths from first to last file: " << paths(row_count, col_count) << endl;
}

unsigned long long paths(int r, int c) {
  // if rows are less than 2, the king only has one path to the last file
  // if columns are less than 2, the king is already in the last file.
  if (r < 2 || c < 2) {
    return 1;
  }

  unsigned long long a[r][c];
 
 // dynamically adds the number of paths the king 
 // can take to reach the next file.
  for (int n = 0; n < c; n++) {
    for (int m = 0; m < r; m++) {
      if (n == 0) {
        a[m][n] = 1;
      } else if (m == 0) {
        a[m][n] = a[m][n - 1] + a[m + 1][n - 1];
      } else if (m == r-1) {
        a[m][n] = a[m][n - 1] + a[m - 1][n - 1];
      } else {
        a[m][n] = a[m - 1][n - 1] + a[m][n - 1] + a[m + 1][n - 1];
      }
    }
  }

  // totals up the number of paths the king can take to reach
  // each cell in the last file.
  unsigned long long total = 0;
  for(int i = 0; i < r; i++) {
    total += a[i][c-1];
  }
  return total;
}