#include <bits/stdc++.h>
using namespace std;

char esc;
int mn, n, l, r, m[400], f[400];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> esc >> l >> r;
    if(esc == 'M') m[l]++, m[r+1]--;
    else f[l]++, f[r+1]--;
  }
  for(int i = 1; i <= 366; i++) m[i] += m[i-1], f[i] += f[i-1], mn = max(mn, min(m[i], f[i]));
  cout << 2*mn << endl;
}
