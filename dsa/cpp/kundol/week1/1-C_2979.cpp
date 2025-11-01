#include <bits/stdc++.h>

using namespace std;

map<int, int> charges;
int num_cars[101];
int sum = 0;

int main(int argc, char **argv) {
  charges.insert({0, 0});
  for (int i = 1; i <= 3; i++) {
    cin >> charges[i];
  }

  for (int i = 0; i < 3; i++) {
    int arrive, depart;
    cin >> arrive >> depart;
    for (int j = arrive; j < depart; j++)
      num_cars[j]++;
  }

  for (int i = 0; i <= 100; i++) {
    sum += charges[num_cars[i]] * num_cars[i];
  }

  cout << sum << endl;

  return 0;
}