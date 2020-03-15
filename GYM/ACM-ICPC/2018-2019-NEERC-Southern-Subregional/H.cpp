#include <bits/stdc++.h>
using namespace std;

int cnt, n, m, l, r, e, b;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  cin >> b >> l >> e >> r;
  
  for(int i = 1; i <= n; i++){
    if(i >= b and i <= e) cnt += ((l-1)&1) + ((m-r)&1);
    else cnt += (m&1);
  }

  cout << (cnt+1)/2 << endl;

}
