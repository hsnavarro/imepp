#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
int n, c[N], p;
vector<int> ans;

bool ok(int i){
  if(c[i] == 0) return false;
  for(auto x : adj[i]) if(c[x] == 0) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> p >> c[i];
    if(p != -1) adj[p].push_back(i);
  }

  for(int i = 1; i <= n; i++){
    if(ok(i)) ans.push_back(i);
  }

  if(!ans.size()) cout << -1 << endl;
  else {
    for(auto x : ans) cout << x << " ";
    cout << endl;
  }


}
