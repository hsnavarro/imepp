#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 1e5+5;

int t, n, k;
vector<int> g[N];
int taken[N], got[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
      taken[i] = got[i] = 0;
      cin >> k;
      g[i].resize(k);
      for(int j = 0; j < k; j++) cin >> g[i][j];
    }

    // simulate
    for(int i = 1; i <= n; i++) {
      int k = 0;
      while(k < g[i].size() and taken[g[i][k]]) k++;
      if(k != g[i].size()) got[i] = 1, taken[g[i][k]] = 1;
    }

    int idx1 = -1, idx2 = -1;
    for(int i = 1; i <= n; i++) if(!taken[i]) idx2 = i;
    for(int i = 1; i <= n; i++) if(!got[i]) idx1 = i;

    if(idx1 == -1 and idx2 == -1) cout << "OPTIMAL\n";
    else {
      cout << "IMPROVE\n";
      cout << idx1 << " " << idx2 << "\n";
    }
  }

}
