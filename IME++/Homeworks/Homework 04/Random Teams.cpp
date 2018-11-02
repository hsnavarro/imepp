#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, mx, mn, k1, k2, k3;

ll comb(ll k){
    ll aux = k*(k-1)/2;
    return aux;
}

int main(){
    scanf("%lld%lld", &n, &m);

    k1 = n-m+1;
    mx = comb(k1);

    k2 = n/m;
    k3 = k2 + 1;
    ll aux1 = n - k2*m;
    ll aux2 = m - aux1;

    mn = aux1*comb(k3) + aux2*comb(k2);

    printf("%lld %lld\n", mn, mx);

    return 0;
}