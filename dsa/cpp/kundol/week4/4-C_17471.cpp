#include <bits/stdc++.h>

using namespace std;

int N;
int poplulation[11];
int marks[11]; // 1 - red, 2 - blue, 3 - connected red, 4 - connected blue
vector<int> adj[11];

void DFS(int region, int mark) {
  for (int &neighbor : adj[region]) {
    if (marks[neighbor] != mark) continue;
    marks[neighbor] = mark + 2;
    DFS(neighbor, mark);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Get input
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> poplulation[i];
  }
  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    while (num--) {
      int temp;
      cin >> temp;
      adj[i].push_back(temp);
    }
  }

  // Check All Combinations
  int ans = 10000;
  for (int i = 1; i < (1 << N) - 2; i++) {
    vector<int> red, blue;
    fill(marks, marks+11, 0);

    // Separate into 2 groups according to each index bit
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        red.push_back(j + 1);
        marks[j + 1] = 1;
      } else {
        blue.push_back(j + 1);
        marks[j + 1] = 2;
      }
    }

    // Check connectivity
    bool not_connected = false;
    marks[red[0]] += 2;
    DFS(red[0], 1);
    for (int k = 1; k <= N; k++) {
      if (marks[k] == 1) {
        not_connected = true;
        break;
      }
    }
    if (not_connected) continue;
    marks[blue[0]] += 2;
    DFS(blue[0], 2);
    for (int k = 1; k <= N; k++) {
      if (marks[k] == 2) {
        not_connected = true;
        break;
      }
    }
    if (not_connected) continue;

    // Calculate population difference
    int red_pop = 0, blue_pop = 0;
    for (int &r : red)
      red_pop += poplulation[r];
    for (int &b : blue)
      blue_pop += poplulation[b];

    // Update answer
    ans = min(ans, abs(red_pop-blue_pop));

    if (ans == 0) {
      cout << 0 << '\n';
      return 0;
    }
  }

  // Print answer
  if (ans == 10000) ans = -1;
  cout << ans << '\n';

  return 0;
}