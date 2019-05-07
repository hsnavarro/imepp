#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a, b;
double EPS = 1e-9;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  scanf("%d", &n);
  while(n--){
    scanf("%lld %lld", &a, &b);
    ll cube = cbrt(a*b) + EPS;
    if(cube*cube*cube == a*b and !(a%cube) and !(b%cube)) printf("Yes\n");
    else printf("No\n");
  }
}
