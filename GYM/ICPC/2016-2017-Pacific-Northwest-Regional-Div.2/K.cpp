#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int l[6], r[6];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  for(int i = 0; i < 6; i++) cin >> l[i];
  for(int i = 0; i < 6; i++) cin >> r[i];

  // prob_win = # of pair (x, y) where x > y / 36
  // prob_draw = # of pair(x, y) where x == y / 36

  // prob = prob_win + prob_draw * prob_win + prob_draw^2 * prob_win + ....

  ld prob_win = 0, prob_draw = 0;

  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++) {
      if(l[i] > r[j]) prob_win++;
      if(l[i] == r[j]) prob_draw++;
    }

  prob_win /= 36.0;
  prob_draw /= 36.0;

  cout << fixed << setprecision(5) << (prob_win / (1.0 - prob_draw)) << "\n";
}
