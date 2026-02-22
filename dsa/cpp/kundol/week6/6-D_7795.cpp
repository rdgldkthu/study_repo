#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int cnt = 0, idx = 0;
    for (int a : A) {
      while (idx < M && a > B[idx]) idx++;
      cnt += idx;
    }
    cout << cnt << '\n';
  }

  return 0;
}
