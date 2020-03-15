#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

int q, x, a, mex;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q >> x;
  while(q--) {
    cin >> a;
    cnt[a%x]++;
    while(cnt[mex%x]) cnt[mex%x]--, mex++;
    cout << mex << "\n";
  }
}
