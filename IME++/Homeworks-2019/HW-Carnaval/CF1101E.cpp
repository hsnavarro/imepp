#include <bits/stdc++.h>
using namespace std;

int n, x, y, hm, wm;
char esc;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> esc >> x >> y;
    if(x < y) swap(x, y);
    if(esc == '+')  hm = max(hm, x), wm = max(wm, y);
    else cout << (x >= hm and y >= wm ? "YES" : "NO") << endl;
  }
}
