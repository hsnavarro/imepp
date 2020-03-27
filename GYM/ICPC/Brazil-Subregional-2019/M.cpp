#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int n, c, t;
int a[N];

bool test(int x){
  int sum = 0, cut = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > x) return false;
    if(sum + a[i] > x) sum = a[i], cut++;
    else sum += a[i];
  }
  if(sum > x) cut++;
  return cut < c;
}

int bin(int l = 0, int r = 1e9 + 5){
  int mid;
  while(l != r){
    mid = (l+r)/2;
    if(test(mid)) r = mid;
    else l = mid + 1;
  }
  return l;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> c >> t;
  for(int i = 0; i < n; i++) cin >> a[i]; 
  cout << (bin() + t - 1)/t << "\n";
} 
