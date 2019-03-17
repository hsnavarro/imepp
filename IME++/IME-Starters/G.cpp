#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll c, n, res;

ll fexp (ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % mod;
        b = (b*b) % mod;
        e >>= 1;
    }
    return ans;
}

ll fat(ll c, ll n){
    ll x = c - 2*n;
    ll ans = 1;
    while(x != (c-3*n)){
        ans = 1ll*ans*x%MOD;
        x--;
    }

    return ans;
}

int main(){
    scanf("%lld %lld", &n, &c);

    res = fat(c, n)*fexp(6, n, MOD)%MOD;

    printf("%lld\n", res);

}