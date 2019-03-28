#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, a, b, p, last, cond = 1, v[N];
set<int> s, m;
vector<int> adj[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i < n; i++) s.insert(i);
  for(int i = 1; i < n; i++){
    cin >> a >> b;
    if(max(a, b) != n) cond = 0;
    v[a]++, v[b]++;
    m.insert(a), m.insert(b);
  }
  if(!cond) return cout << "NO" << endl, 0;
  m.erase(n);
  for(auto x : m){
    last = n;
    auto it = s.begin();
    while(s.size() and it != s.end() and v[x]){
      p = *it, it++;
      if(v[x] == 1) { s.erase(x), adj[last].push_back(x); break; }
      if(p <= x) s.erase(p), adj[last].push_back(p), last = p;
      else break;
      v[x]--;
    }
  }
  if(s.size()) return cout << "NO" << endl, 0;
  cout << "YES" << endl;
  for(int i = 1; i <= n; i++)
    for(auto x : adj[i]) cout << x << " " << i << endl;
}
