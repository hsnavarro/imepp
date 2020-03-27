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
const int N = 4e6+5;

int t, n, q, trie[N][2], idx[N], cnt = 1;
vector<int> v;
ll x;

void add(int id) {
  int u = 1;
  for(auto x : v) {
    if(!trie[u][x]) trie[u][x] = ++cnt;
    u = trie[u][x];
  }
  idx[u] = min(idx[u], id);
}

int find() {
  int u = 1;
  for(auto x : v) {
    if(trie[u][x^1]) u = trie[u][x^1];
    else u = trie[u][x];
  }
  return idx[u];
}

void convert(ll x) {
  v.clear();
  for(int i = 32; i >= 0; i--) {
    if(x & (1ll << i)) v.pb(1);
    else v.pb(0);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    memset(trie, 0, sizeof trie);
    memset(idx, 63, sizeof idx);
    cnt = 1;
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
      cin >> x;
      convert(x);
      add(i);
    }

    while(q--) {
      cin >> x;
      convert(x);
      cout << find() << "\n";
    }
    cout << "\n";
  }
}

