#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7; 
ll n, fat[N], f1, f2;

ll fexp(ll b, int e = MOD - 2){
  ll ans = 1;
  while(e){
    if(e & 1) ans = ans*b%MOD;
    b = b*b%MOD, e >>= 1;
  }
  return ans;
}

int main(){
  scanf("%lld", &n);
  fat[0] = 1;
  for(int i = 1; i < 2*n; i++) fat[i] = i*fat[i-1]%MOD;

  f1 = fexp(fat[n]), f2 = fexp(fat[n-1]);
  ll res = (((2*fat[2*n-1])%MOD*(f1*f2%MOD))%MOD - n + MOD)%MOD;
  printf("%lld\n", res);
}

