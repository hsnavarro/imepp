#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, u, v, c, enter[N];
ll dp[N][6];
vector<pii> adj[N];
vector<vector<int>> tup[6][5], fat[6];

void prepare(int x = 1, int p = -1){ for(auto u : adj[x]) if(u.st != p) enter[u.st] = u.nd, prepare(u.st, x); }

void generate() {
  vector<int> aux;
  for(int color = 1; color <= 5; color++) {
    for(int i = 1; i < (1 << 5); i++){
      aux.clear();
      if((1 << (color-1)) & i) continue;
      for(int j = 0; j < 5; j++) if((1 << j) & i) aux.pb(j+1);
      do {
        tup[color][aux.size()].pb(aux);
      } while(next_permutation(aux.begin(), aux.end()));
    }
  }

  for(int i = 1; i < (1 << 5); i++) {
    aux.clear();
    for(int j = 0; j < 5; j++) if((1 << j) & i) aux.pb(j+1);
    do {
      fat[aux.size()].pb(aux);
    } while(next_permutation(aux.begin(), aux.end()));
  }
}

void dfs(int u = 1, int p = -1){
  vector<int> aux;
  for(auto v : adj[u]) if(v.st != p) aux.pb(v.st), dfs(v.st, u);
  
  if(aux.size() >= 5) { cout << 0 << "\n"; exit(0); }

  if(!aux.size()){
    if(!enter[u]) for(int i = 1; i <= 5; i++) dp[u][i] = 1ll;
    else dp[u][enter[u]] = 1ll;
    return;
  }
  
  if(!enter[u]){
    for(int i = 1; i <= 5; i++){
      vector<vector<int>> col = tup[i][aux.size()];
      for(auto pos : col) {
        ll mult = 1ll;
        for(int k = 0; k < pos.size(); k++) mult = (mult * dp[aux[k]][pos[k]]) % MOD;
        dp[u][i] = (dp[u][i] + mult) % MOD;
      }
    }
  } else {
    vector<vector<int>> col = tup[enter[u]][aux.size()];
    for(auto pos : col) {
      ll mult = 1ll;
      for(int k = 0; k < pos.size(); k++) mult = (mult * dp[aux[k]][pos[k]]) % MOD;
      dp[u][enter[u]] = (dp[u][enter[u]] + mult) % MOD;
    }
  }
}


int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  if(n == 1) return cout << 1 << endl, 0;
  
  prepare(), generate(), dfs();

  ll sum = 0ll;
  vector<vector<int>> col = fat[adj[1].size()];
  for(auto pos : col){
    ll mult = 1ll;
    for(int k = 0; k < pos.size(); k++) mult = (mult * dp[adj[1][k].st][pos[k]]) % MOD;
    sum = (sum + mult) % MOD;
  }
  cout << sum << "\n";
}
