#include <bits/stdc++.h>
using namespace std;

int a, b, t;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  while((a > 0 and b > 0) and !(a == 1 and b == 1)){
    if(a < b) swap(a, b);
    a -= 2;
    b ++;
    t++;
  }
  cout << t << endl;
}
