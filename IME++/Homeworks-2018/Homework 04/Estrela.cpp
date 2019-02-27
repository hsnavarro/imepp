#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+5;

ll n, ans;
int cmp[N];
vector<ll> p;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
            for (ll j = i*i; j < N; j+=i) cmp[j]=1;
            p.push_back(i);
        }
}

int main(){
    primes();
    while(~scanf("%lld", &n)){
        ans = n;
        for (int i = 0; p[i]*p[i] <= n; i++) {
            if(!(n%p[i])){
                ans /= p[i];
                ans *= p[i]-1;
            }
            while (!(n%p[i])) n /= p[i];
        }

        if (n > 1) {
            ans *= n-1;
            ans /= n;
        }

        printf("%lld\n", ans/2);
    }

    return 0;
}

