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
const int N = 3e5+5;

int n, m, mn[N], p[N];
int a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a;
    mn[i+1] = n;
    p[a] = i+1;
  }
  mn[n+1] = n;

  while(m--) {
    cin >> a >> b;
    int left = p[a];
    int right = p[b];
    if(right < left) swap(left, right);
    mn[left] = min(mn[left], right - 1);
  }

  for(int i = n; i >= 0; i--) mn[i] = min(mn[i], mn[i+1]); 

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += 1ll*mn[i] - 1ll*i + 1ll;
  }
  cout << ans << "\n";
}

