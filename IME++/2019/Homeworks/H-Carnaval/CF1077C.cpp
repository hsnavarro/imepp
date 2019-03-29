#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, sum, mx1, mx2;
vector<int> v, ans;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] > mx1) mx2 = mx1, mx1 = v[i];
    else if(v[i] > mx2) mx2 = v[i];
    sum += v[i];
  }

  

  for(int i = 0; i < v.size(); i++){
    if(v[i] != mx1 and sum - v[i] == 2*mx1) ans.push_back(i+1);
    if(v[i] == mx1 and sum - v[i] == 2*mx2) ans.push_back(i+1);
  }

  cout << ans.size() << endl;
  for(auto x : ans) cout << x << " ";
  cout << endl;
}
