#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, mx;
string s;
int mask[26], ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cin >> s;
  for(int i = 0; i < n; i++) {
    int b = 0;
    for(int j = s[i] - 'a' + 1; j < 26; j++) b |= mask[j];
    for(int k = 0; k < 26; k++) if(!(b & (1 << k))) {
      ans[i] = k+1;
      mx = max(mx, k+1);
      mask[s[i] - 'a'] |= (1 << k);
      break;
    }
  }
  cout << mx << "\n";
  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
