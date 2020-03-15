#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int s, n, m, cmp[N], cnt;
vector<vector<int>> vis, grid;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int deep){
  vis[x][y] = 1;
  cmp[cnt]++;
  //if(deep == 8) cout << "x, y, cnt: " << x << " " << y << " " << cnt << endl;
  for(int k = 0; k < 4; k++){
    int xn = x + dx[k];
    int yn = y + dy[k];
    if(xn < 0 or xn >= n or yn < 0 or yn >= m) continue;
    if(!vis[xn][yn] and grid[xn][yn] >= deep) dfs(xn, yn, deep);
  }
}

bool test(int x){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) vis[i][j] = 0;
  memset(cmp, 0, sizeof cmp);

  cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) 
      if(!vis[i][j] and grid[i][j] >= x) cnt++, dfs(i, j, x);
/*
  if(x == 8){
  cout << "start" << endl;
    for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cout << vis[i][j];
    cout << endl;
  }
    for(int i = 0; i <= n; i++) cout << cmp[i] << endl;
  }
*/

  for(int i = 0; i <= n*m; i++) if(cmp[i] >= s) return true;
  return false;
}

int bin(){
  int l = 0, r = int(1e8);
  while(l != r){
    int mid = (l+r)/2;
    if(test(mid)) l = mid+1;
    else r = mid;
  }
  if(!test(l)) l--;
  return l;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s >> n >> m;
  vis.resize(n, vector<int>(m));
  grid.resize(n, vector<int>(m));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
  cout << bin() << "\n";
}
