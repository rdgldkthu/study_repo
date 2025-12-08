#include <bits/stdc++.h>

using namespace std;

vector<int> children[50];
int N, root, removed_node;

int DFS(int idx) {
  if (idx == removed_node) {
    return 0;
  }

  int child_cnt = 0;
  int leaf_sum = 0;

  for (int &child : children[idx]) {
    if (child == removed_node) {
      continue;
    }
    child_cnt++;
    leaf_sum += DFS(child);
  }

  if (child_cnt == 0) {
    return 1;
  }

  return leaf_sum;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int parent;
    cin >> parent;
    if (parent == -1) {
      root = i;
    }
    else {
      children[parent].push_back(i);
    }
  }

  cin >> removed_node;

  cout << ((root == removed_node) ? 0 : DFS(root)) << '\n';

  return 0;
}