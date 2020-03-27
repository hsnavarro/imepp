#include <bits/stdc++.h>
using namespace std;

int n, v;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> v;
  for(int i = 1; i <= 9; i++) cout << (((n*v)*i + 9)/10) << " ";
  cout << "\n";
}
