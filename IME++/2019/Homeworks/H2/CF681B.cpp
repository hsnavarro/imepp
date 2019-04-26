#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(ll a = 0; a <= 1e3; a++){
    for(ll b = 0; b <= 1e4; b++){
      ll c = (n - 1234567*a - 123456*b)/1234;
      if(c >= 0 and 1234567*a + 123456*b + 1234*c == n) return cout << "YES" << endl, 0; 
    }
  }
  cout << "NO" << endl;
}
