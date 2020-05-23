#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 5;

struct state {
  int i, j;  
  string s;
};

bool operator< (const state &a, const state &b) {
  return tie(a.i, a.j, a.s) < tie(b.i, b.j, b.s);
}

map<state, int> dist;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

string pos_str = "LRDU", com;

int n, m;
int sx, sy, ex, ey;
char grid[N][N];

bool check(int xn, int yn) {
  return xn >= 0 and xn < n and yn >= 0 and yn < m and grid[xn][yn] != '#';
}

void bfs(int i, int j) {
  dist[{i, j, ""}] = 0;
  queue<state> q;
  q.push({i, j, ""});

  while(q.size()) {
    int x = q.front().i;
    int y = q.front().j;
    string s = q.front().s;
    q.pop();

    int xn, yn, inc, pos;
    string sn;
    for(int k = 0; k < 4; k++) {
      pos = s.size();
      xn = x + dx[k];
      yn = y + dy[k];

      if(!check(xn, yn) or grid[x][y] == 'E') xn = x, yn = y;

      if(pos == com.size() or com[pos] != pos_str[k]) sn = s, inc = 1;
      else sn = s + com[pos], inc = 0;

      if(dist.count({xn, yn, sn})) continue;

      dist[{xn, yn, sn}] = dist[{x, y, s}] + inc;
      q.push({xn, yn, sn});
    }
  }


}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'R') sx = i, sy = j;
      if(grid[i][j] == 'E') ex = i, ey = j;
    }

  cin >> com;
  bfs(sx, sy);

  cout << dist[{ex, ey, com}] << "\n";

}
