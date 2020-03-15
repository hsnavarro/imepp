#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
 
int t, n, d, lf[N], rt[N], nok[N], p[N], h[N];
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> d;
    int lb = 0, aux = 0;

    for(int i = 1; i <= n; i++) {
      lf[i] = rt[i] = nok[i] = p[i] = h[i] = 0;
      lb += aux;
      if(!(i & (i+1))) aux++;
    }
 
    for(int i = 1; i+1 <= n; i++) p[i+1] = i, h[i+1] = i, lf[i] = i+1;
    int ans = (n*(n-1))/2;
    if(ans < d or d < lb) cout << "NO\n";
    else {
      int cond = 1;
      while(ans != d) {
        int mn = INF, node = -1;
        for(int i = 1; i <= n; i++) 
          if(!lf[i] and !rt[i] and !nok[i] and h[i] < mn) mn = h[i], node = i;
        
        if(node == -1) { cond = 0; break; }
 
        int nxt = -1;
        for(int i = 1; i <= n; i++) 
          if(h[i] == mn - 2 and (!lf[i] or !rt[i])) { nxt = i; break; }
 
        if(nxt != -1) {
          if(lf[p[node]] == node) lf[p[node]] = 0;
          else rt[p[node]] = 0;
          p[node] = nxt;
          if(!lf[nxt]) lf[nxt] = node;
          else rt[nxt] = node;
          h[node] = h[nxt] + 1;
          ans--;
        } else nok[node] = 1;
      }
      if(!cond) cout << "NO\n";
      else {
        cout << "YES\n";
        for(int i = 2; i <= n; i++) cout << p[i] << " ";
        cout << "\n";
      }
    }
  }
}
