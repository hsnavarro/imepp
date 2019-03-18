#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int n, m, esc, l, r, v[N], u[N];

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> v[i], u[i] = v[i];
  sort(u + 1, u + n + 1);
  for(int i = 1; i <= n; i++) v[i] += v[i-1], u[i] += u[i-1];
  cin >> m;
  while(m--){
    cin >> esc >> l >> r;
    if(esc == 1) cout << v[r] - v[l-1] << endl;
    else cout << u[r] - u[l-1] << endl;
  }
}
