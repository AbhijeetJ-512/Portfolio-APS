#include <algorithm>
#include <cstdlib> // for malloc and free
#include <cstring> // for memset
#include <iostream>
#include <string>
using namespace std;

struct Diff {
  char operation; // ' ' for no change, '-' for deletion, '+' for addition
  std::string text;
};

void addDiff(Diff *result, int &resultIndex, char operation,
             const std::string &text) {
  result[resultIndex].operation = operation;
  result[resultIndex].text = text;
  resultIndex++;
}

// Function to find the differences between two sequences using Myers' algorithm
Diff *myersDiff(const std::string &a, const std::string &b, int &diffCount) {
  int N = a.size();
  int M = b.size();
  int max = N + M;
  int *V = (int *)malloc((2 * max + 1) * sizeof(int));
  memset(V, 0, (2 * max + 1) * sizeof(int));
  Diff *result = (Diff *)malloc((N + M) * sizeof(Diff));
  diffCount = 0;

  for (int D = 0; D <= max; ++D) {
    for (int k = -D; k <= D; k += 2) {
      int x, y;
      if (k == -D || (k != D && V[k - 1 + max] < V[k + 1 + max])) {
        x = V[k + 1 + max];
      } else {
        x = V[k - 1 + max] + 1;
      }
      y = x - k;

      while (x < N && y < M && a[x] == b[y]) {
        x++;
        y++;
      }

      V[k + max] = x;

      if (x >= N && y >= M) {
        while (D >= 0) {
          int kPrev = k;
          if (k == -D || (k != D && V[k - 1 + max] < V[k + 1 + max])) {
            k = k + 1;
          } else {
            k = k - 1;
          }
          int xPrev = V[k + max];
          int yPrev = xPrev - k;

          while (x > xPrev && y > yPrev) {
            addDiff(result, diffCount, ' ', std::string(1, a[x - 1]));
            x--;
            y--;
          }

          if (x > xPrev) {
            addDiff(result, diffCount, '-', std::string(1, a[x - 1]));
            x--;
          } else if (y > yPrev) {
            addDiff(result, diffCount, '+', std::string(1, b[y - 1]));
            y--;
          }

          D--;
        }

        reverse(result, result + diffCount); // Reverse the result array
        free(V);
        return result;
      }
    }
  }

  free(V);
  return result;
}

int main() {
  std::string a = "1234";
  std::string b = "12345";

  int diffCount;
  Diff *diffs = myersDiff(a, b, diffCount);

  // Print the result
  for (int i = 0; i < diffCount; ++i) {
    cout << diffs[i].operation << diffs[i].text;
  }
  cout << endl;

  free(diffs);

  return 0;
}
