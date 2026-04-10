#include <bits/stdc++.h>
using namespace std;

struct Counter {
  int end_time;
  int id;

  bool operator<(const Counter &other) const {
    if (this->end_time == other.end_time) return this->id > other.id;
    return this->end_time > other.end_time;
  }
};

struct Customer {
  int end_time;
  int counter;
  int id;

  bool operator<(const Customer &other) const {
    if (this->end_time == other.end_time) return this->counter < other.counter;
    return this->end_time > other.end_time;
  }
};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, k;
  cin >> N >> k;


  priority_queue<Counter> counter_pq;
  for (int i = 1; i <= k; i++) {
    counter_pq.push({0, i});
  }

  priority_queue<Customer> customer_pq;
  for (int i = 0; i < N; i++) {
    int id, w;
    cin >> id >> w;

    Counter counter = counter_pq.top();
    counter_pq.pop();

    int end_time = counter.end_time + w;
    counter_pq.push({end_time, counter.id});

    customer_pq.push({end_time, counter.id, id});
  }

  long long ans = 0LL;
  long long coef = 1LL;
  while (!customer_pq.empty()) {
    auto customer = customer_pq.top();
    customer_pq.pop();
    ans += static_cast<long long>(customer.id) * coef++;
  }

  cout << ans << "\n";

  return 0;
}
