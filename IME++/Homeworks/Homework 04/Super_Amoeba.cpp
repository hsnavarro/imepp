#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll t, n, m, x, y;

ll fexp(ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = ans*b % mod;
        b = b*b % mod;
        e /= 2;
    }
    return ans;
}

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &m, &n);
        ll a = fexp(m, n, MOD) - 1;
        ll b = fexp(m, n, MOD);
        x = a*fexp(m-1, MOD-2, MOD)%MOD;
        y = b%MOD;

        printf("%lld %lld\n", x, y);
    }
    return 0;
}


