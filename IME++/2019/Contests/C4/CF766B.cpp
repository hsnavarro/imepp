#include <bits/stdc++.h>
using namespace std;

bool isOk(int a, int b, int c){
  if(a < b + c and b < a + c and c < a + b) return true;
  return false;
}

const int N = 1e5+5;

int n, v[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  for(int i = 0; i + 2 < n; i++) if(isOk(v[i], v[i+1], v[i+2]))
    return cout << "YES" << endl, 0;
  cout << "NO" << endl;
}
