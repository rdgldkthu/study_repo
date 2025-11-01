// Solve with combination
#include <bits/stdc++.h>

using namespace std;

int arr[9];

int sum7(int arr[]) {
  int sum = 0;
  for (int i = 0; i < 7; i++)
    sum += arr[i];
  return sum;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++)
    cin >> arr[i];

  for (int i = 0; i < 8; i++) {
    swap(arr[i], arr[7]);
    for (int j = i + 1; j < 9; j++) {
      int idx = (j == 7) ? i : j;
      swap(arr[idx], arr[8]);
      if (sum7(arr) == 100)
        break;
      swap(arr[idx], arr[8]);
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