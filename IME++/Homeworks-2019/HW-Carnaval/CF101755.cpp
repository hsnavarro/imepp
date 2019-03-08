#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

bool test(int x){
  int s = 0, cnt = 0;
  for(auto p : a){
    if(cnt == x and p > s) continue;
    if(cnt < x and p > s)  cnt++;
    s++;
  }
  return s >= m;
}

int bin(int l = 0, int r = n){
  int mid;
  while(l < r){
    mid = (l+r)/2;
    if(test(mid)) r = mid;
    else l = mid+1;
  }
  return l;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  cout << bin() << endl;
}
