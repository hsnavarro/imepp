#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int t, n, a[N], lst[N];

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    int ans = INF;
    for(int i = 1; i <= n; i++) lst[i] = -1;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
      if(lst[a[i]] != -1) ans = min(ans, i - lst[a[i]] + 1);
      lst[a[i]] = i;
    }
    printf("%d\n", ans == INF ? -1 : ans);
  }
}
