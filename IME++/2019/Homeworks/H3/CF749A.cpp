#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if(n & 1){
    n -= 3, n /= 2;
    cout << n + 1 << endl;
    while(n--) cout << 2 << " ";
    cout << 3 << endl;
  }else{
    n /= 2;
    cout << n << endl;
    while(n--) cout << 2 << " ";
    cout << endl;
  }
}
