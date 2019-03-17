#include <bits/stdc++.h>
using namespace std;

int sum, mn = 0x3f3f3f3f, idx, n, k;
vector<int> f;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  f.resize(n);
  for(int i = 0; i < n; i++) cin >> f[i];
  for(int i = 0; i < k; i++) sum += f[i];
  for(int i = k-1; i < n; i++) {
    if(sum < mn){
      mn = sum;
      idx = i - k + 1 + 1;
    }
    sum += f[i+1] - f[i - k + 1];
  }
  cout << idx << endl;
}
