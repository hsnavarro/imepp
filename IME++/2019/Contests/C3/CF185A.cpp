#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll n;
ll fexp(ll b, ll e, ll mod){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans*b) % mod;
        b = (b*b) % mod;
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    cout << (n ? (fexp(2, n-1, MOD) + fexp(2, 2*n-1, MOD)) % MOD : 1) << endl;
}
