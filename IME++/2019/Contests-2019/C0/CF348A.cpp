#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;

ll n, a[N];

bool test(ll x){
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    if(x - a[i] < 0) return false;
    sum += x - a[i];
  }
  return sum >= x;
}

ll bin(ll l = 1, ll r = 2e9){
  ll mid;
  while(l < r){
    mid = (l+r)/2;
    if(test(mid)) r = mid;
    else l = mid+1;
  }
  return l;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  cout << bin() << endl;
}
