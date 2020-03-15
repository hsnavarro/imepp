#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, p;
int a[N], fail[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p;
  p--;
  for(int i = 0; i < n-1; i++) cin >> a[i];
  for(int i = 0; i < n-1; i++) cin >> fail[i], fail[i]--;

  for(int i = 0; i < (1 << (n-1)); i++) {
    int x = p, cond = 1;
    for(int j = 0; j < n-1; j++) {
      if((1 << j) & i) x = (x + a[j]) % n;
      else x = (x - a[j] + n) % n;
      if(x == fail[j]) cond = 0;
    }
    if(cond) return cout << "Yes\n", 0;
  }
  cout << "No\n";
}
