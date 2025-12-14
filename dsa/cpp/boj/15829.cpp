#include <bits/stdc++.h>
using namespace std;

long long lut[50];

int main(int argc, char **argv) {
  int L;
  cin >> L;

  long long temp = 1;
  for (int i = 0; i < L; ++i) {
    lut[i] = temp;
    temp = (temp * 31) % 1234567891;
  }

  string str;
  cin >> str;

  long long sum = 0;
  for (int i = 0; i < L; ++i) {
    long long num = str[i] - 'a' + 1;
    sum = (sum + num * lut[i]) % 1234567891;
  }

  cout << sum << endl;

  return 0;
}