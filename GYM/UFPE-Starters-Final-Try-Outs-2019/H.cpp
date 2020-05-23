#include <bits/stdc++.h>
using namespace std;

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

typedef unsigned long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

ll n, m, mod, a[N][N], b[N][N], c[N][N], d[N][N];
ll k, u, v, uu, vv;

int cond = 0;

ll add(ll a, ll b, int ok) {
  if(ok){  
    if(a + b > 0) return 1;
    return 0;
  }
  a += b;
  if(a >= mod) return a - mod;
  return a;
}

void multa(int ok) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) c[i][j] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        c[i][j] = add(c[i][j], (a[i][k]*b[k][j]) % mod, ok);
      }
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) a[i][j] = c[i][j];
}

void multb(int ok) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) c[i][j] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        c[i][j] = add(c[i][j], (b[i][k]*b[k][j]) % mod, ok);
      }
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) b[i][j] = c[i][j];
}


void fexp(ll k, int ok) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) a[i][j] = (i == j);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) b[i][j] = d[i][j];

  while(k) {
    if(k & 1ll) multa(ok);
    multb(ok);
    k = k/2;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> mod;
  cin >> k >> u >> v;
  while(m--) {
    cin >> uu >> vv;
    d[uu][vv] = d[vv][uu] = 1;
  }
  fexp(k, 1);
  if(!a[u][v]) cout << "Mendes will sleep in peace.\n";
  else {
    fexp(k, 0);
    cout << a[u][v] << "\n";
  }
  
}

