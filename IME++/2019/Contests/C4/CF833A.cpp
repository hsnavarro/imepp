#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a, b, cube;
double EPS = 1e-9;

int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%d%d", &a, &b);
    cube = cbrt(1ll*a*b) + EPS;
    1ll*cube*cube*cube == 1ll*a*b and !(a%cube) and !(b%cube) ? 
      printf("Yes\n") : printf("No\n");
  }
}
