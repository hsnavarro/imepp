#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50+5;

int a, r, c, r0[N], c0[N], r1[N], c1[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> a;
      a ? (r1[i]++, c1[j]++) : (r0[i]++, c0[j]++);
    }
  }

  ll sum = 0;
  for(int i = 0; i < r; i++) sum += (1ll << r1[i]) + (1ll << r0[i]) - 2*1ll;
  for(int i = 0; i < c; i++) sum += (1ll << c1[i]) + (1ll << c0[i]) - 2*1ll;
  cout << sum - 1ll*r*c << endl;
}
