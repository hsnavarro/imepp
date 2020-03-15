#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

set<int> adj[N], adjt[N];
vector<int> st;
int n, k, p[N], q[N], cmp[N], cnt, vis[N];

void dfs(int u) {
  vis[u] = 1;
  for(auto v : adj[u]) if(!vis[v]) dfs(v);
  st.push_back(u);
}

void dfst(int u) {
  vis[u] = 0;
  cmp[u] = cnt;
  for(auto v : adjt[u]) if(vis[v]) dfst(v);
}

void add(int a, int b) {
  adj[a].insert(b);
  adjt[b].insert(a);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < n; i++) cin >> q[i];

  for(int i = 0; i+1 < n; i++) add(p[i], p[i+1]);
  for(int i = 0; i+1 < n; i++) add(q[i], q[i+1]);
  for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
  while(st.size()) {
    if(vis[st.back()]) cnt++, dfst(st.back());
    st.pop_back();
  }

  if(cnt < k) cout << "NO\n";
  else {
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << char(min(cmp[i] + 'a' - 1, (int)'z'));
    cout << "\n";
  }

}
