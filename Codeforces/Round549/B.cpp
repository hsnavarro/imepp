#include <bits/stdc++.h>
using namespace std;

long long n, res;
char cnt = '1';

long long calc(string aux){
  long long prod = 1;
  for(auto x : aux) prod = prod*(max(1, x - '0'));
  return prod;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if(n < 10) return cout << n << endl, 0;
  string aux = to_string(n);
  res = max(res, calc(aux));
  for(int i = aux.size() - 1; i >= 1; i--){
    if(aux[i] == '9') continue;
    else aux[i] = '9', aux[i-1] = int(aux[i-1]) - 1;
    res = max(res, calc(aux));
  }
  cout << res << endl;
}
