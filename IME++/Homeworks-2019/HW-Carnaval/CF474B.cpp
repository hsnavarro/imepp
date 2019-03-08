#include <bits/stdc++.h>
using namespace std;

int n, m, sum, x;
vector<int> a, s;

int bin(int x, int l = 0, int r = n-1){
  int mid;
  while(l < r){
    mid = (l+r)/2;
    if(s[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return l+1;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n);
  s.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    s[i] = sum;
  }

  cin >> m;
  while(m--){
  cin >> x;
  cout << bin(x) << endl;
  }
}
