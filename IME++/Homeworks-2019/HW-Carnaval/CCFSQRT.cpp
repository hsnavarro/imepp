#include <bits/stdc++.h>
using namespace std;

int t, n;

int bin_search(int x, int l = 1, int r = 10000){
  int mid;
  while(l != r){
    mid = (l+r)/2;
    if(mid*mid == x) return mid;
    if(mid*mid < x) l = mid + 1;
    else r = mid;
  }
  return l-1;
}


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    cout << bin_search(n) << endl;
  }
}
