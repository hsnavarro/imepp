#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 500 + 5;

vector<int> adj[N];
int n, m, q, ans, age[N], name[N], id[N], vis[N], a, b;
char esc;

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]) 
    if(!vis[v]) ans = min(ans, age[name[v]]), dfs(v);
}

int32_t main(){
  while(scanf("%d%d%d", &n, &m, &q) != EOF){
    for(int i = 1; i <= n; i++) scanf("%d", &age[i]), name[i] = i, id[i] = i;
    for(int i = 0; i < m; i++){
      scanf("%d%d", &a, &b);
      adj[b].push_back(a);
    }
    for(int i = 0; i < q; i++){
      scanf(" %c", &esc);
      if(esc == 'P') {
        for(int i = 1; i <= n; i++) vis[i] = 0;
        ans = INF;
        scanf("%d", &a);
        dfs(id[a]);
        if(ans != INF) printf("%d\n", ans);
        else printf("*\n");
      } else {
        scanf("%d%d", &a, &b);
        swap(id[a], id[b]);
        name[id[a]] = a;
        name[id[b]] = b;
      }
    }
    for(int i = 1; i <= n; i++) adj[i].clear();
  }
} 
