#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string A, B;
  cin >> A >> B;

  string result = "";
  int carry = 0;

  int i = A.length() - 1;
  int j = B.length() - 1;

  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += A[i--] - '0';
    if (j >= 0) sum += B[j--] - '0';

    carry = sum / 10;
    result += sum % 10 + '0';
  }

  reverse(result.begin(), result.end());
  cout << result << '\n';

  return 0;
}
