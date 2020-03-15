#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

const int N = 1e3 + 10;

int n, m, cnt, vis[N][N], x, y = 1;
map<pair<pii, pii>, int> forb;
string s;
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, -1, 1};

bool in_grid (int x, int y) {
  if(x <= 0 or x > m+3) return false;
  if(y <= 0 or y > n+3) return false;
  return true;
}

void dfs(int x, int y) {
  vis[x][y] = 1;
  for(int i = 0; i < 8; i++) {
    int xn = x + dx[i];
    int yn = y + dy[i];
    if(!in_grid(xn, yn)) continue;
    if(vis[xn][yn]) continue;
    if(forb[{{x, y}, {xn, yn}}]) continue;
    dfs(xn, yn);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s;
    y++, x = 2;
    for(int j = 0; j < m; j++, x++) {
      if(s[j] == '/') {
        vis[x][y+1] = vis[x+1][y] = 1;
        forb[{{x, y}, {x+1, y+1}}] = 1;
        forb[{{x+1, y+1}, {x, y}}] = 1;
      } 
      if(s[j] == '\\') {
        vis[x][y] = vis[x+1][y+1] = 1;
        forb[{{x+1, y}, {x, y+1}}] = 1;
        forb[{{x, y+1}, {x+1, y}}] = 1;
      }
    }
  }
  
  for(int i = 1; i <= m+3; i++)
    for(int j = 1; j <= n+3; j++) if(!vis[i][j]) cnt++, dfs(i, j);

  cout << cnt-1 << "\n";
}
