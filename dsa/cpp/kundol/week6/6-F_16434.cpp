#include <bits/stdc++.h>
using namespace std;

struct Room {
  int t;
  int a;
  int h;
};

int N, H_ATK;
long long l = 1, r = 2 * 10e17, ans = 2 * 10e17;
vector<Room> rooms;

bool solve(long long H_MaxHP) {
  long long H_CurHP = H_MaxHP;
  long long H_CurATK = H_ATK;

  for (auto [t, a, h] : rooms) {
    if (t == 1) {
      long long cnt = (h + H_CurATK - 1) / H_CurATK;
      if ((cnt - 1) > (H_CurHP - 1) / a) return false;
      H_CurHP -= (cnt - 1) * a;
    } else {
      H_CurATK += a;
      H_CurHP = min(H_MaxHP, H_CurHP + h);
    }
  }
  return true;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> H_ATK;

  rooms.resize(N);

  for (int i = 0; i < N; i++) cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;

  while (l <= r) {
    long long mid = (l + r) / 2;
    if (solve(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
