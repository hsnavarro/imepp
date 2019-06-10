#include <bits/stdc++.h>
using namespace std;

int n, m, idx;
vector<int> a;


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  while(a[(idx)/2] < m and idx < n) idx++;
  cout << n - idx << endl;
}
