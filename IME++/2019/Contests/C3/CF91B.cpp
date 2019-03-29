#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, lower, a[N], mn[N];

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  mn[n] = INF; 
  for(int i = n-1; i >= 0; i--) mn[i] = min(a[i], mn[i+1]);
  for(int i = 0; i < n; i++){
    lower = lower_bound(mn + i + 1, mn + n, a[i]) - mn;
    printf("%d ", lower - i - 2);
  }
  printf("\n");
}
