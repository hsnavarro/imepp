#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e3 + 5;

int n, k, p[N];

map<int, int> pq1, pq2;
// -val dp, pts

int main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  while(~scanf("%d%d", &n, &k)){
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    pq1.clear(), pq2.clear();
    pq1[0] = 0;
    for(int i = 1; i <= n; i++){
      if(i & 1){
        for(auto x : pq1) {
          int pts = x.st;
          int val = x.nd;
          if(pts >= k){
            if(pq2.count(pts-k)) pq2[pts-k] = min(pq2[pts-k], val);
            else pq2[pts-k] = val;
          }

          if(pq2.count(pts+1)) pq2[pts+1] = min(pq2[pts+1], val + p[i-1]);
          pq2[pts+1] = val + p[i-1];
        }
        pq1.clear();
      } else {
        for(auto x : pq2) {
          int pts = x.st;
          int val = x.nd;
          if(pts >= k){
            if(pq1.count(pts-k)) pq1[pts-k] = min(pq1[pts-k], val);
            else pq1[pts-k] = val;
          }

          if(pq1.count(pts+1)) pq1[pts+1] = min(pq1[pts+1], val + p[i-1]);
          pq1[pts+1] = val + p[i-1];
        }
        pq2.clear();
      }
    }

    int op1 = 1e9 + 5, op2 = 1e9 + 5;
    for(auto x : pq1) op1 = min(op1, x.nd);
    for(auto x : pq2) op2 = min(op2, x.nd);
    printf("%d\n", min(op1, op2));
  }
}
