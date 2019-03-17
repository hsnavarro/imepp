#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, p[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> p[i];
  for(int j = 1; j <= n; j++){
    for(int i = 1; i <= n; i++){
      if(p[i] == j) cout << i << " ";
    }
  }

  cout << endl;
}
