#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e4;
const int X = 1e9;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int vis[N], num[N], dist[N];
vector<int> adj[N];
int m, n, aux, ans = INF, cont;
queue <int> q;

void bfs (int s) {
   cl(vis, 0);
    vis[s] = 1;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if(num[v] == 0) ans = min(ans,dist[u]+1);
            if(num[v] == 2) continue;
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v]++;
                q.push(v);
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m * n; i++) {
        scanf(" %d", &aux);
        num[i] = aux;

        if(i%m) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        if(i < n*m + 1 - m) {
            adj[i].push_back(i + m);
            adj[i + m].push_back(i);
        }
    }

    for (int i = 1; i <= m*n; ++i) {
      if(num[i] == 3) {
          bfs(i);
          break;
      }
    }

/*
    for (int i = 1; i <= m*n; i++) {
           printf("%d ", dist[i]);
        if(!(i%m)) printf("\n");
    }
*/

    printf("%d\n", ans);




    return 0;
}