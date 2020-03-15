#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

int n, a[2*N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2*n; i++) scanf("%d", &a[i]);
  sort(a, a+2*n);

  int mi = 2e9, ma = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i] + a[2*n-i-1];
    mi = min(mi, v);
    ma = max(ma, v);
  }

  printf("%d\n", ma - mi);
  return 0;
}

