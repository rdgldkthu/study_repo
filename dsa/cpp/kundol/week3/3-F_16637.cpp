#include <bits/stdc++.h>

using namespace std;

vector<int> num;
vector<char> oper;
int ans = INT_MIN;

int operate(char oper, int a, int b) {
    if (oper == '+') return a + b;
    if (oper == '-') return a - b;
    if (oper == '*') return a * b;
    return -1;
}

void solve(int id, int val) {
  if (id == oper.size()) {
    ans = max(ans, val);
    return;
  }
  solve(id + 1, operate(oper[id], val, num[id+1]));
  if (id + 2 < num.size()) {
    int temp = operate(oper[id+1], num[id+1], num[id+2]);
    solve(id + 2, operate(oper[id], val, temp));
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  string exp;
  cin >> exp;

  for (int i = 0; i < N; ++i) {
    if (i%2)
      oper.push_back(exp[i]);
    else
      num.push_back(exp[i] - '0');
  }

  solve(0, num[0]);

  cout << ans << endl;

  return 0;
}