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
const int N = 1e2+5;

int dx[] = {0, 0, 0, -1, -1, -1, 1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

ll grid[N][N], newgrid[N][N];
ll m, n, rep, aux;
set<ll> s;

ll blur(int x, int y) {
  ll sum = 0;

  for(int k = 0; k < 9; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if(nx == -1) nx = n-1;
    if(ny == -1) ny = m-1;
    if(nx == n) nx = 0;
    if(ny == m) ny = 0;

    sum += grid[nx][ny];
  }

  return sum;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> m >> n >> rep;

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }

  while(rep--) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        newgrid[i][j] = blur(i, j);
      }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) grid[i][j] = newgrid[i][j];
  }

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++) s.insert(grid[i][j]);

  cout << s.size() << "\n";

}

