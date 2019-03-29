#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll h, x;

ll bin(ll l = 1, ll r = (1ll << h)){
  ll mid, sum = 0, alt = 0, dir = 1;
  while(l < r){
    mid = (l+r)/2;
    if(mid >= x) r = mid, dir ? dir ^= 1 : sum += (1ll << (h-alt)) - 1;
    else l = mid+1, !dir ? dir ^= 1 : sum += (1ll << (h-alt)) - 1;
    alt++, sum++;
  }
  return sum;
}

int main(){
  scanf("%lld%lld", &h, &x);
  printf("%lld\n", bin());
}
