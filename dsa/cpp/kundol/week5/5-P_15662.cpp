#include <bits/stdc++.h>
using namespace std;

int T, K, id, dir, ans = 0;
vector<bitset<8>> gears;

int rotate(int id, int dir, int prev_id) {
  if (id - 1 >= 0 && id - 1 != prev_id &&
      gears[id - 1].test(5) ^ gears[id].test(1))
    rotate(id - 1, -dir, id);
  if (id + 1 < T && id + 1 != prev_id &&
      gears[id].test(5) ^ gears[id + 1].test(1))
    rotate(id + 1, -dir, id);
  if (dir == 1) { // clockwise
    auto temp = gears[id].test(0);
    gears[id] >>= 1;
    gears[id] |= (temp << 7);
  } else { // counter-clockwise
    auto temp = gears[id].test(7);
    gears[id] <<= 1;
    gears[id] |= temp;
  }
  return 1;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  gears.resize(T);
  for (int i = 0; i < T; i++) cin >> gears[i];

  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> id >> dir;
    rotate(id - 1, dir, -1);
  }

  for (auto &gear : gears)
    if (gear.test(7)) ans++;

  cout << ans << '\n';
  return 0;
}
