#include <bits/stdc++.h>
using namespace std;

string s, aux;
int dig[10], mx = -1, ok;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  for(int i = 0; i < s.size(); i++) dig[i] = s[i] - '0', mx = max(mx, dig[i]);
  cout << mx << endl;
  for(int k = 0; k < mx; k++){
    aux = "", ok = 0;
    for(int i = 0; i < s.size(); i++){
      if(dig[i]) aux += '1', dig[i]--, ok = 1;
      else if(ok) aux += '0';
    }
    if(!aux.size()) break;
    cout << aux << " ";
  }
  cout << endl;
}
