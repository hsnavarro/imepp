#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int t, n, m, p, s, st[4*N], mons[N];
vector<pair<int, int>> her, sch;

int main(){
  scanf("%d", &t);
  while(t--){
    her.clear(), sch.clear();
    scanf("%d", &n);
    for(int i = 0; i <= 4*n; i++) st[i] = -INF;
    for(int i = 1; i <= n; i++) scanf("%d", &mons[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
      scanf("%d%d", &p, &s);
      her.push_back({p, s});
    }
    sort(her.begin(), her.end());
    int mx = 0;
    for(int i = her.size() - 1; i >= 0; i--){
      mx = max(mx, her[i].second);
      sch.push_back({her[i].first, mx});
    }
    sort(sch.begin(), sch.end());

    int pos = 1, ok = 1, cnt = 0;
    while(pos <= n){
      int ptr = 0, mx = 0;
      while(pos+ptr <= n){
        mx = max(mx, mons[pos+ptr]);
        int pos = 
          lower_bound(sch.begin(), sch.end(), (pair<int, int>) {mx, 0})
          - sch.begin();
        if(pos == sch.size() or sch[pos].second < ptr+1) {
          if(!ptr) ok = 0;
          break;
        }
        ptr++;
      }
      if(!ok) break;
      pos += ptr, cnt++;
    }
    printf("%d\n", ok ? cnt : -1);
  }
}
