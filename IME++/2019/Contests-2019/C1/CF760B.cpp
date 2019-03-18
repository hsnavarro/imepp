#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;
int sum(int x, int y){
  if(y > x-1) return (x-1)*x/2 + y - (x-1);
  return (x-1+x-y)*y/2;
}

bool test(int x){ return sum(x, k-1) + x + sum(x, n-k) <= m; }

int bin(int l = 1, int r = m){
  int mid;
  while(l < r){
    mid = (l+r)/2;
    if(test(mid)) l = mid + 1;
    else r = mid;
  }
  return test(l) ? l : l-1;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  cout << bin() << endl;
}
