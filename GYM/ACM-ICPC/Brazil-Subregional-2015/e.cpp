#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, b;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> b;
  int ax = (n - sqrt(n*n - b + 1))/2, falta = b - 4*ax*(n-ax) - 1, sh = n-1-2*ax;
  if(falta <= sh) cout << ax+1 << " " << ax+1+falta << "\n";
  else if(falta <= 2*sh) cout << ax+1 + falta-sh << " " << n-ax << "\n";
  else if(falta <= 3*sh) cout << n-ax << " " << n-ax - falta + 2*sh << "\n";
  else cout << n-ax - falta + 3*sh << " " << ax+1 << "\n";
}
