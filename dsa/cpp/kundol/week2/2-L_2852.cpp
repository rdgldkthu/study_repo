#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int scores[2] = {0, 0};
  int time_lead_SS[2] = {0, 0};
  int MM, SS, prev_MM = 0, prev_SS = 0, time_diff;

  while (N--) {
    int team;
    string timestamp;
    cin >> team >> timestamp;
    auto pos = timestamp.find(':');
    MM = stoi(timestamp.substr(0, pos));
    SS = stoi(timestamp.substr(pos + 1));

    time_diff = (MM - prev_MM) * 60 + (SS - prev_SS);

    if (scores[0] > scores[1])
      time_lead_SS[0] += time_diff;
    else if (scores[1] > scores[0])
      time_lead_SS[1] += time_diff;

    scores[team - 1]++;

    prev_MM = MM;
    prev_SS = SS;
  }

  time_diff = (47 - prev_MM) * 60 + (60 - prev_SS);

  if (scores[0] > scores[1])
    time_lead_SS[0] += time_diff;
  else if (scores[1] > scores[0])
    time_lead_SS[1] += time_diff;

  cout << setw(2) << setfill('0') << time_lead_SS[0] / 60 << ':'
       << setw(2) << setfill('0') << time_lead_SS[0] % 60 << '\n';
  cout << setw(2) << setfill('0') << time_lead_SS[1] / 60 << ':'
       << setw(2) << setfill('0') << time_lead_SS[1] % 60 << '\n';
  return 0;
}