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

const int N = 1e5 + 5;

int n, k, ans, p[N], pts;
priority_queue<int> pq;

int main(){
  while(~scanf("%d%d", &n, &k)){
    ans = 0;
    for(int i = 0; i < n; i++) scanf("%d", &p[i]), ans += p[i];
    
    for(int i = 0; i < n; i++){
      if(pts >= k) pts -= k, pq.push(-p[i]);
      else {
        pts++;
        if(pq.size() and -pq.top() < p[i]) pq.pop(), pq.push(-p[i]);
      }
    }

    while(pq.size()){
      int u = pq.top();
      pq.pop();
      ans += u;
    }

    printf("%d\n", ans);
  }

}
