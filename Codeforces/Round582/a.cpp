#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
int n, p, imp, a;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a, a&1 ? imp++ : p++;
  cout << min(imp, p) << "\n";
}
