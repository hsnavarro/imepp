#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

#define int long long

map<int, tuple<int, int, int>> mp;
int n, m, k, v[N], ope[N], p[N];
int a, b, c;

void op(int x, int v){
  auto m = mp[x];
  int l = get<0>(m);
  int r = get<1>(m);
  int d = get<2>(m);
  p[l] += v*d;
  p[r+1] -= v*d;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) cin >> v[i];
  for(int i = 1; i <= m; i++){
    cin >> a >> b >> c;
    mp[i] = {a, b, c};
  }
  while(k--){
    cin >> a >> b;
    ope[a]++;
    ope[b+1]--;
  }
  for(int i = 1; i <= N; i++) ope[i] += ope[i-1];
  for(int i = 1; i <= N; i++) op(i, ope[i]);
  for(int i = 1; i <= N; i++) p[i] += p[i-1];
  for(int i = 1; i <= N; i++) v[i] += p[i];
  for(int i = 1; i <= n; i++) cout << v[i] << " ";
  cout << endl;
}
