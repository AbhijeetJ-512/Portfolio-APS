#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = new int[n1];
  int *R = new int[n2];

  for (int i = 0; i < n1; ++i)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }

  delete[] L;
  delete[] R;
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void commitActivityAnalysis(int commits[], int size) {
  mergeSort(commits, 0, size - 1);

  // Display sorted commit activity
  cout << "Sorted Commit Activity:" << endl;
  for (int i = 0; i < size; ++i) {
    cout << commits[i] << " commits" << endl;
  }
}

int main() {
  // number of commits per day over a period
  int commitsPerDay[] = {10, 5, 15, 7, 20, 12, 8};
  int size = sizeof(commitsPerDay) / sizeof(commitsPerDay[0]);

  // Perform commit activity analysis
  commitActivityAnalysis(commitsPerDay, size);

  return 0;
}