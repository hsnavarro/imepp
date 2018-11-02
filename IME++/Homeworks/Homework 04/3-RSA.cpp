#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e18;

ll n;
vector<ll> ans;

void primes(ll n){
    ans.clear();
    for(ll i = 3; i*i < M; i+= 2){
        if(n%i == 0) ans.push_back(i);
        if(ans.size() == 2) break;
    }

    ll aux = n/(ans[0]*ans[1]);
    ans.push_back(aux);
}

int main(){
    while(scanf("%lld", &n), n) {
        primes(n);
        printf("%lld = %lld x %lld x %lld\n", n, ans[0], ans[1], ans[2]);
    }
    return 0;
}