#include <bits/stdc++.h>
using namespace std;

int T, N, M, num;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> N;
    vector<int> note(N);
    for (int i = 0; i < N; i++) cin >> note[i];
    sort(note.begin(), note.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> num;
      int l = 0, r = N - 1, mid;
      while (l <= r) {
        mid = (l + r) / 2;
        if (note[mid] == num) {
          break;
        } else if (note[mid] > num) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      if (note[mid] == num) cout << "1\n";
      else cout << "0\n";
    }
  }

  return 0;
}
