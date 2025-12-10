#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> houses, chicken_places;
vector<vector<int>> combinations;

void generateCombinations(int start, vector<int> v) {
  if (v.size() == M) {
    combinations.push_back(v);
    return;
  }
  for (int i = start + 1; i < chicken_places.size(); ++i) {
    v.push_back(i);
    generateCombinations(i, v);
    v.pop_back();
  }
}

int calculateChickenDistance(pair<int, int> house,
                             pair<int, int> chicken_place) {
  return abs(house.first - chicken_place.first) +
         abs(house.second - chicken_place.second);
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int temp;
      cin >> temp;
      if (temp == 1)
        houses.push_back({i, j});
      if (temp == 2)
        chicken_places.push_back({i, j});
    }
  }

  vector<int> v;
  generateCombinations(-1, v);

  int ans = INT_MAX;
  for (vector<int> combi : combinations) {
    int sum = 0;
    for (pair<int, int> house : houses) {
        int dist = 2 * N;
        for (int idx : combi) {
            pair<int, int> chicken_place = chicken_places[idx];
            dist = min(dist, calculateChickenDistance(house, chicken_place));
        }
        sum += dist;
    }
    ans = min(ans, sum);
  }

  cout << ans << '\n';

  return 0;
}