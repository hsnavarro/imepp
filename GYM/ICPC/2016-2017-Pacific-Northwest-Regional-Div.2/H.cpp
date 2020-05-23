#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 5;

char grid[N][N];
int n, m, vis[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool check(int x, int y) { return x >= 0 and x < n and y >= 0 and y < m; }

void dfs(int x, int y) {
  vis[x][y] = 1;
  int xn, yn;
  for(int k = 0; k < 4; k++) {
    xn = x + dx[k];
    yn = y + dy[k];
    if(check(xn, yn) and !vis[xn][yn] and grid[xn][yn] != 'W') dfs(xn, yn);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];

  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(grid[i][j] == 'L' and !vis[i][j]) ans++, dfs(i, j);

  cout << ans << "\n";
}
