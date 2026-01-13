#include <bits/stdc++.h>
using namespace std;

vector<int> split(string list) {
  vector<int> result;
  int pos = 1;
  auto end = list.find(',', pos);
  while (end != list.npos) {
    result.push_back(stoi(list.substr(pos, end - pos)));
    pos = end + 1;
    end = list.find(',', pos);
  }
  result.push_back(stoi(list.substr(pos, list.size() - pos - 1)));
  return result;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    string prog, list;
    int N;
    int order = 0; // 0 : normal, 1 : reverse
    int drop_cnt_front = 0, drop_cnt_back = 0;
    bool drop_when_empty = false;
    cin >> prog;
    cin >> N;
    cin >> list;
    vector<int> v = N ? split(list) : vector<int>();

    // iterate though the commands and track list order and drop counts
    for (const char &cmd : prog) {
      if (cmd == 'R') {
        order ^= 1;
      } else if (cmd == 'D') {
        if (N - drop_cnt_back - drop_cnt_front == 0) {
          drop_when_empty = true;
          break;
        }
        order ? drop_cnt_back++ : drop_cnt_front++;
      }
    }

    // print error if attempt to drop from an empty list
    if (drop_when_empty) {
      cout << "error\n";
      continue;
    }

    // print result if not error
    if (order) { // reverse
      cout << '[';
      int print_cnt = 0;
      for (auto it = v.rbegin() + drop_cnt_back; it != v.rend() - drop_cnt_front; it++) {
        cout << *it;
        print_cnt++;
        if (print_cnt < N - drop_cnt_back - drop_cnt_front) cout << ',';
      }
      cout << "]\n";
    } else { // normal
      cout << '[';
      int print_cnt = 0;
      for (int id = drop_cnt_front; id < v.size()-drop_cnt_back; id++) {
        cout << v[id];
        print_cnt++;
        if (print_cnt < N - drop_cnt_back - drop_cnt_front) cout << ',';
      }
      cout << "]\n";
    }
  }

  return 0;
}
