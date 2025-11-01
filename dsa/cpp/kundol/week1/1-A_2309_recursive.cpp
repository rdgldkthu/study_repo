// Solve with recursive permutation
#include <bits/stdc++.h>

using namespace std;

int arr[9];
int n = 9, r = 7;

void solve() {
  int sum = 0;
  for (int i = 0; i < r; i++)
    sum += arr[i];
  if (sum == 100) {
    sort(arr, arr + r);
    for (int i = 0; i < r; i++)
      cout << arr[i] << endl;
    exit(0);
  }
}

void makePermutation(int n, int r, int depth) {
  if (r == depth) {
    solve();
    return;
  }
  for (int i = depth; i < n; i++) {
    swap(arr[i], arr[depth]);
    makePermutation(n, r, depth + 1);
    swap(arr[i], arr[depth]);
  }
  return;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  makePermutation(n, r, 0);

  return 0;
}