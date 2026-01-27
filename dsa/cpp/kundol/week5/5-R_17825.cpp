#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int horses[4], scores[4], dice[10], points[33];
vector<int> adj[33];

void setMap() {
  for (int i = 0; i < 20; i++) adj[i].push_back(i + 1);
  for (int i = 1; i <= 20; i++) points[i] = 2 * i;

  adj[5].push_back(21); adj[21].push_back(22);
  adj[22].push_back(23); adj[23].push_back(26);
  points[21] = 13; points[22] = 16; points[23] = 19;

  adj[10].push_back(24); adj[24].push_back(25);
  adj[25].push_back(26);
  points[24] = 22; points[25] = 24; points[26] = 25;

  adj[15].push_back(27); adj[27].push_back(28);
  adj[28].push_back(29); adj[29].push_back(26);
  points[27] = 28; points[28] = 27; points[29] = 26;

  adj[26].push_back(30); adj[30].push_back(31);
  adj[31].push_back(20);
  points[30] = 30; points[31] = 35;

  adj[20].push_back(32);
  points[32] = 0;
}

int move(int loc, int steps) {
  if (adj[loc].size() > 1) {
    loc = adj[loc][1];
    steps--;
  }
  while (steps--) {
    if (loc == 32) break;
    loc = adj[loc][0];
  }
  return loc;
}

bool isOccupied(int loc) {
  for (int i = 0; i < 4; i++)
    if (loc != 32 && loc == horses[i]) return true;
  return false;
}

void solve (int id) {
  if (id == 10) {
    ans = max(ans, scores[0] + scores[1] + scores[2] + scores[3]);
    return;
  }
  int steps = dice[id];
  for (int i = 0; i < 4; i++) {
    int curr = horses[i];
    if (curr == 32) continue;
    int next = move(curr, steps);
    if (isOccupied(next)) continue;
    int prev = horses[i];
    horses[i] = next;
    scores[i] += points[next];
    solve(id + 1);
    horses[i] = prev;
    scores[i] -= points[next];
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  setMap();

  for (int i = 0; i < 10; i++) cin >> dice[i];

  solve(0);

  cout << ans << '\n';

  return 0;
}
