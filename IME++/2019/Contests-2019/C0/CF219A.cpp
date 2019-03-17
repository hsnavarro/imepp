#include <bits/stdc++.h>
using namespace std;

string a;
int k;
map<char, int> f;

int main(){
  cin >> k >> a;
  for(auto p : a) f[p]++;
  int cond = 1;
  for(auto x : f) if(x.second % k != 0) cond = 0;
  if(!cond) cout << -1 << endl;
  else{
    string aux;
    for(auto x : f){
      x.second /= k;
      while(x.second --) aux += x.first;
    }
    string ans;
    while(k--) ans += aux;
    cout << ans << endl;
  }
}
