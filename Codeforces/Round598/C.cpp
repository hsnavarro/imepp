#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1000 + 5;

int n, m, d, pos, need, sum;
int c[N], ans[N];

int main(){
  scanf("%d%d%d", &n, &m, &d);
  for(int i = 1; i <= m; i++) scanf("%d", &c[i]), sum += c[i];
  need = n - sum; 
  if((d-1)*(m+1) < need) return printf("NO\n"), 0;
  printf("YES\n");
  pos = min(need+1, d), need -= min(need, d-1);
  for(int i = 1; i <= m; i++){
    for(int j = pos; j < pos+c[i]; j++) ans[j] = i;
    pos += c[i] - 1 + min(need+1, d), need -= min(need, d-1);
  }

  for(int j = 1; j <= n; j++) printf("%d ", ans[j]);
  printf("\n");
}
