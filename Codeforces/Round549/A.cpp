#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, num0, num1, v[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    if(v[i] == 1) num1++;
    else num0++;
  }

  for(int i = 0; i < n; i++){
    if(v[i] == 1) num1--;
    else num0--;
    if(num0 == 0 or num1 == 0) return cout << i+1 << endl, 0;
  }

}
