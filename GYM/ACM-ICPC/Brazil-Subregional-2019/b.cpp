#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, a, mx = -1, id;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a; 
    if(a > mx) mx = a, id = i;
  }
  cout << (id == 1 ? "S\n" : "N\n");
}

