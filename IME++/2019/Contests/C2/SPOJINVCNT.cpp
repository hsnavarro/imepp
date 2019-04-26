#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+5;
const int M = 2e5+5;

#define int long long

int t, n, bit[N], v[M];

void add(int p, int v) {
  for (p+=2; p<N; p+=p&-p) bit[p] += v;
}

int query(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    memset(bit, 0, sizeof(bit));
    memset(v, 0, sizeof(v));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int inv = 0;
    for(int i = n-1; i >= 0; i--) inv += query(v[i]), add(v[i], 1);
    cout << inv << endl;
  }




}
