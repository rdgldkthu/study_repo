#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    int num;
    cin >> num;

    if (num == 0)
      break;

    string str = to_string(num);
    int mid = str.size() / 2;
    string half1 = str.substr(0, mid);
    string rhalf1 = string(half1.rbegin(), half1.rend());
    string half2;
    if (str.size() % 2)
      half2 = str.substr(mid + 1);
    else
      half2 = str.substr(mid);

    if (rhalf1 == half2)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}