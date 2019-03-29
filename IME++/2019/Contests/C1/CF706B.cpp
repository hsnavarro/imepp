#include <bits/stdc++.h>
using namespace std;

int n, q, m;
vector<int> x;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  x.resize(n);
  for(int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  cin >> q;
  while(q--){
    cin >> m;
    cout << upper_bound(x.begin(), x.end(), m) - x.begin() << endl;
  }
}
