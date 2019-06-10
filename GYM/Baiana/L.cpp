#include <bits/stdc++.h>
using namespace std;

int a, mat[7][7];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 7; j++){
      cin >> a;
      mat[i][j] = a;
    }
  }

  for(int k = 0; k < 7; k++){
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 7; i++){
      cnt1 += mat[i][k];
      cnt2 += mat[k][i];
    }
    cout << max(cnt1, cnt2) << endl;
  }
}
