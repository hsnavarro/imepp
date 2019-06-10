#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, p[N];
vector<pair<int, char>> adj[N];
string s, ans;

string cmp(string a, string b){
  int idxa = a.size() - 1, idxb = b.size() - 1;
  while(idxa >= 0 and idxb >= 0 and a[idxa] == b[idxb]) idxa--, idxb--;
  if(idxa >= 0 and idxb >= 0) return a[idxa] > b[idxb] ? a : b;
  return idxa == -1 ? b : a;
}

void dfs(int x, string &res){
  if(res.size()) ans = cmp(ans, res);
  for(auto u : adj[x]) {
    res += u.second;
    dfs(u.first, res);
    res.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n-1; i++) cin >> p[i+1];
  cin >> s;
  for(int i = 1; i <= s.size(); i++) adj[p[i+1]].push_back({i+1, s[i-1]});
  string res;
  dfs(1, res);
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
