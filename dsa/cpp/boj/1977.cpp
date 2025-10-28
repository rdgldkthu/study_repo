#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

  int M; // <=N    , natural number
  int N; // <=10000, natural number
  cin >> M;
  cin >> N;

  // sum of all the perfect square numbers between N and M
  int sum = 0;

  int cur = floor(sqrt(N));

  // calculate the sum
  int squared = 0;
  while (cur * cur >= M) {
    squared = cur * cur;
    if (M <= squared <= N) {
      sum += squared;
    }
    --cur;
  }

  // output results
  if (sum == 0)
    cout << -1 << endl;
  else {
    cout << sum << endl;
    cout << (cur + 1) * (cur + 1) << endl;
  }

  return 0;
}
