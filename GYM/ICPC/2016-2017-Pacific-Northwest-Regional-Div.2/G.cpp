#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 50 + 5;

int n, m;
char big[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> big[i][j];


  for(int k = 0; k < N; k++) {
    for(int j = 0; j < m; j++) {
      for(int i = 0; i+1 < n; i++) if(big[i][j] == 'o' and big[i+1][j] == '.') big[i][j] = '.', big[i+1][j] = 'o';
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) cout << big[i][j];
    cout << "\n";
  }
}
