#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
  // Create two temporary vectors to store the left and right halves of the array.
  vector<int> left_temp(mid - left + 1);
  vector<int> right_temp(right - mid);

  // Copy the left and right halves of the array to the temporary vectors.
  for (int i = 0; i < mid - left + 1; i++) {
    left_temp[i] = arr[left + i];
  }
  for (int i = 0; i < right - mid; i++) {
    right_temp[i] = arr[mid + 1 + i];
  }

  // Merge the two temporary vectors back into the original array.
  int i = 0, j = 0, k = left;
  while (i < left_temp.size() && j < right_temp.size()) {
    if (left_temp[i] <= right_temp[j]) {
      arr[k] = left_temp[i];
      i++;
    } else {
      arr[k] = right_temp[j];
      j++;
    }
    k++;
  }

  // Copy any remaining elements from the temporary vectors to the original array.
  while (i < left_temp.size()) {
    arr[k] = left_temp[i];
    i++;
    k++;
  }
  while (j < right_temp.size()) {
    arr[k] = right_temp[j];
    j++;
    k++;
  }
}

void merge_sort(vector<int>& arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    // Recursively sort the left and right halves of the array.
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    // Merge the two sorted halves of the array.
    merge(arr, left, mid, right);
  }
}

int main() {
  vector<int> arr = {5, 3, 2, 1, 4};

  // Merge sort the array.
  merge_sort(arr, 0, arr.size() - 1);

  // Print the sorted array.
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
