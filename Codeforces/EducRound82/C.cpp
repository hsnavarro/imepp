#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 30 + 5;

int t;
string s, form;
vector<int> adj[N];
int vis[N], in[N];
map<pair<int, int>, int> used;

int dfs(int x, int p) {
  //cout << "x " << char(x - 1 + 'a') << endl;
  vis[x] = 1;
  form += char(x - 1 + 'a');
  for(auto v : adj[x]) {
    if(v == p) continue;
    if(vis[v]) return 0;
    dfs(v, x);
  }
  return 1;
}

void clear() {
  form.clear();
  for(int i = 0; i < N; i++) in[i] = 0, vis[i] = 0, adj[i].clear();
  used.clear();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    clear();
    cin >> s;
    for(int i = 0; i+1 < s.size(); i++) {
      int a = s[i] - 'a' + 1;
      int b = s[i+1] - 'a' + 1;
      if(a > b) swap(a, b);
      if(used[{a, b}]) continue;
      used[{a, b}] = 1;
      adj[a].pb(b);
      adj[b].pb(a);
      //cout << "a, b " << a << " " << b << endl;
      in[a]++, in[b]++;
    }
    int cond = 0;
    for(int i = 0; i < N; i++){ 
      if(in[i] == 1) { cond = dfs(i, -1); break; }
    }

    for(int i = 0; i < N; i++) if(in[i] > 2) cond = 0;

    if(!cond and s.size() > 1){ cout << "NO\n"; continue; }

    cout << "YES\n";
    for(int i = 1; i <= 26; i++) if(!vis[i]) cout << char(i - 1 + 'a');
    cout << form;
    cout << "\n";
  }
}
