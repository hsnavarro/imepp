#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, cnt, in[N];
vector<string> ans;
map<string, int> id;
map<int, string> name;
vector<int> adj[N];

void kahn(){
  priority_queue<int, vector<int>, greater<int> > q;
  for(int i = 1; i <= n; i++) if(!in[i]) q.push(i);
  while(q.size()){
    int v = q.top(); q.pop();
    ans.push_back(name[v]);
    for(auto x : adj[v]) if(in[x] and --in[x] == 0) q.push(x);
  }
}

void reset(){
  memset(in, 0, sizeof in);
  id.clear(), name.clear();
  for(int i = 0; i < N; i++) adj[i].clear();
  ans.clear();
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n and ++cnt){
    reset();
    string s;
    for(int i = 1; i <= n; i++){
      cin >> s;
      id[s] = i, name[i] = s;
    }
    cin >> m;
    while(m--){
      string a, b;
      cin >> a >> b;
      adj[id[a]].push_back(id[b]);
      in[id[b]]++;
    }
    kahn();
    cout << "Case #" << cnt << ": Dilbert should drink beverages in this order: ";
    for(auto x : ans) if(x != ans.back()) cout << x << " ";
    cout << ans.back() << ".\n\n";
  }
}
