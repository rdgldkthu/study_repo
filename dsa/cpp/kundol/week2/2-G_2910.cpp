#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
unordered_map<int, pair<int,int>> freqmap; // k: number in message, v: first index, frequency

bool cmp(int a, int b) {
  if (freqmap[a].second == freqmap[b].second) {
    return freqmap[a].first < freqmap[b].first;
  }
  return freqmap[a].second > freqmap[b].second;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, C;
  cin >> N >> C;

  for (int i = 0; i < N; ++i) {
    int t;
    cin >> t;
    nums.push_back(t);
    auto it = freqmap.find(t);
    if (it == freqmap.end()) {
      freqmap.insert({t,{i,0}});
    }
    freqmap[t].second++;
  }

  sort(nums.begin(), nums.end(), cmp);

  for (auto &e : nums)
    cout << e << " ";
  cout << '\n';

  return 0;
}