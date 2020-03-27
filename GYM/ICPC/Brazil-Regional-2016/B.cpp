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

int n, m, a, b, in[N];
int x, y;

int main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  while(~scanf("%d%d%d%d", &n, &m, &a, &b)){
    for(int i = 0; i < m; i++){
      scanf("%d%d", &x, &y);
      in[x]++, in[y]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
      if(in[i] >= a and n - in[i] >= b) ans++;
      in[i] = 0;
    } 
    printf("%d\n", ans);
  }
}
