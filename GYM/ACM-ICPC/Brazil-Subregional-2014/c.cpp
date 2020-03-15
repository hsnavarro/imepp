#include <bits/stdc++.h>
using namespace std;

map<string, int> freq;

int m, n, a, b, c, d, x, y, z;

struct plane{ int a, b, c, d; };

plane inp[505];

bool eval(int x, int y, int z, plane r){
  return r.a*x + r.b*y + r.c*z > r.d;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> m >> n;
  for(int i = 0; i < m; i++) 
    cin >> inp[i].a >> inp[i].b >> inp[i].c >> inp[i].d;

  for(int i = 0; i < n; i++){
    cin >> x >> y >> z;
    string aux;
    for(int j = 0; j < m; j++) aux += eval(x, y, z, inp[j]);
    freq[aux]++;
  }
  int ans = 0;
  for(auto x : freq) ans = max(ans, x.second);
  cout << ans << "\n";
}
