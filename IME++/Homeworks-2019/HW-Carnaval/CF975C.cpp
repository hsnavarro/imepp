#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, sum, aux, b;
vector<int> a, k;

int bin(int x, int l = 0, int r = n-1){
  int mid;
  while(l < r){
    mid = (l+r)/2;
    if(a[mid] <= x) l = mid+1;
    else r = mid;
  }
  return l;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  a.resize(n), k.resize(m);
  for(int i = 0; i < n; i++) {
    cin >> b;
    aux += b;
    a[i] = aux;
  }
  for(int i = 0; i < m; i++) cin >> k[i];

  for(int i = 0; i < m; i++){
    sum += k[i];
    if(sum >= aux) sum = 0;
    cout << n - bin(sum) << endl;
  }
}
