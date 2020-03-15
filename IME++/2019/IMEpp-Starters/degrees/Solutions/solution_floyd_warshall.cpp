#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1000 + 5;

int n, m, a, b;
int dist[N][N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  memset(dist, 63, sizeof dist);
  while(m--){
    cin >> a >> b;
    dist[a][b] = dist[b][a] = 1;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int mx = -INF;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      mx = max(mx, dist[i][j]);

  if(mx == INF) cout << "=[" << endl;
  else cout << "=] " << mx << endl;
}
