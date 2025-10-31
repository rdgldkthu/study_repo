#include <bits/stdc++.h>

using namespace std;

int temp;
int arr[9];

int sum7(int arr[]) {
  int sum = 0;
  for (int i = 0; i < 7; i++)
    sum += arr[i];
  return sum;
}

int main(int argc, char **argv) {
  for (int i = 0; i < 9; i++) {
    cin >> temp;
    arr[i] = temp;
  }

  // brute-force
  for (int i = 0; i < 8; i++) {
    swap(arr[i], arr[7]);
    for (int j = i + 1; j < 9; j++) {
      if (j == 7) {
        swap(arr[i], arr[8]);
        if (sum7(arr) == 100)
          break;
        swap(arr[i], arr[8]);
      } else {
        swap(arr[j], arr[8]);
        if (sum7(arr) == 100)
          break;
        swap(arr[j], arr[8]);
      }
    }
    if (sum7(arr) == 100)
      break;
    swap(arr[i], arr[7]);
  }

  sort(arr, arr + 7);
  for (int k = 0; k < 7; k++)
    cout << arr[k] << endl;

  return 0;
}