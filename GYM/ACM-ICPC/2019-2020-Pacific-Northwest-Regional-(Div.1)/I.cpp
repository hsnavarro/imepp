#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 500 + 5;

vector<string> v; 
string s;
vector<int> adj[N];
int n, cnt, vis[N], match[N], ans;

bool find(int x){
  if(vis[x] == cnt) return false;
  vis[x] = cnt;
  for(auto u : adj[x]) { 
    if(!match[u] or find(match[u])) return match[u] = x;
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int sz = v[0].size();

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      int cnt = 0;
      for(int k = 0; k < sz; k++) if(v[i][k] != v[j][k]) cnt++;
      if(cnt <= 2) {
        adj[i+1].pb(j+1);
        adj[j+1].pb(i+1);
      }
    }
  }


  for(int i = 1; i <= n; i++) ++cnt, ans += find(i);
  
  cout << n - ans/2 << "\n";
}
