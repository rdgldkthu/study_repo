#include <bits/stdc++.h>

using namespace std;

int k;
char ineq[10];
bool used_digit[10];
long max_num = 0, min_num = 9876543211;

long vec2num(vector<int> vec) {
  long result = vec[0];
  for (int i = 1; i < vec.size(); ++i)
    result = result * 10 + vec[i];
  return result;
}

void solve(int id, vector<int> v) {
  if (id == k + 1) {
    max_num = max(max_num, vec2num(v));
    min_num = min(min_num, vec2num(v));
    return;
  }
  for (int i = 0; i < 10; ++i) {
    if (used_digit[i]) continue;
    if (id > 0 && ineq[id - 1] == '<' && v[id - 1] > i) continue;
    else if (id > 0 && ineq[id - 1] == '>' && v[id - 1] < i) continue;
    v.push_back(i);
    used_digit[i] = true;
    solve(id + 1, v);
    used_digit[i] = false;
    v.pop_back();
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k;
  for (int i = 0; i < k; ++i)
    cin >> ineq[i];

  vector<int> empty;
  solve(0, empty);

  cout << setw(k + 1) << setfill('0') << max_num << '\n';
  cout << setw(k + 1) << setfill('0') << min_num << '\n';

  return 0;
}