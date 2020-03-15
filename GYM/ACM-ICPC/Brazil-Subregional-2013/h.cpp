#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e6;

int n, k, l, ans[2][2], b[2][2], c[2][2];

void mult(int a[2][2], int b[2][2]){
  memset(c, 0, sizeof c);
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      for(int k = 0; k < 2; k++)
        c[i][j] = (c[i][j] + (a[i][k]*b[k][j])%MOD) % MOD;
}

void cp(int a[2][2], int b[2][2]){
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++) a[i][j] = b[i][j];
}

void fexp(int e){
  while(e){
    if(e & 1) mult(ans, b), cp(ans, c);
    mult(b, b), cp(b, c);
    e = e/2;
  }
}


int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n >> k >> l){
    k %= MOD, l %= MOD;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++) ans[i][j] = (i == j);
    b[0][0] = k, b[0][1] = 1, b[1][0] = l, b[1][1] = 0;
    fexp(n/5-1);
    string resp = to_string(((k*ans[0][0])%MOD + ans[1][0]) %MOD);
    while(resp.size() != 6) resp = "0" + resp;
    cout << resp << "\n";
  }
}
