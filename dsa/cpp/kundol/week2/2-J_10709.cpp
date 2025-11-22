#include <bits/stdc++.h>

using namespace std;

int ans[100][100];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int H, W;
  cin >> H >> W;

  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    int set = -1;
    bool hasCloud = false;
    for (int j = 0; j < W; ++j) {
      char let = s[j];
      if (let == 'c') {
        hasCloud = true;
        set = -1;
      }
      if (hasCloud) {
        ++set;
      }
      ans[i][j] = set;
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}