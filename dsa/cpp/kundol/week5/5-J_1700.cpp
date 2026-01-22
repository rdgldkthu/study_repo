#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 0;
int a[100], visited[101];
vector<int> v;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < K; i++) cin >> a[i];

  for (int i = 0; i < K; i++) {
    if (!visited[a[i]]) {
      if (v.size() == N) {
        int to_replace, dist = 0;
        for(int num : v) {
          int temp_dist = INT_MAX;
          for (int j = i + 1; j < K; j++) {
            if (a[j] == num) {
              temp_dist = j;
              break;
            }
          }
          if (temp_dist > dist) {
            to_replace = num;
            dist = temp_dist;
          }
        }
        v.erase(find(v.begin(), v.end(), to_replace));
        visited[to_replace] = 0;
        ans++;
      }
      v.push_back(a[i]);
      visited[a[i]] = 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
