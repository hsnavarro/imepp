#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e2+5;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;
int dist[N][N];
char grid[N][N];
queue<pair<int, int>> q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];

  memset(dist, 63, sizeof dist);
  dist[0][0] = 0;
  q.push({0, 0});
  while(q.size()) {
    int x = q.front().st;
    int y = q.front().nd;
    q.pop();

    for(int k = 0; k < 4; k++) {
      int nx = x + (grid[x][y] - '0') * dx[k];
      int ny = y + (grid[x][y] - '0')* dy[k];

      if(nx < 0 or ny < 0 or nx >= n or ny >= m) continue;

      if(dist[nx][ny] == INF) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  if(dist[n-1][m-1] == INF) cout << "IMPOSSIBLE\n";
  else cout << dist[n-1][m-1] << "\n";
}

