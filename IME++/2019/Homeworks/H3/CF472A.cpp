#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if(n&1) return cout << 9 << " " << n-9 << endl, 0;
  cout << 4 << " " << n-4 << endl;
}
