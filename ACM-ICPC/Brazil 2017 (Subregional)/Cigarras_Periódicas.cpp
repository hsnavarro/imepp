//
// Created by Henrique Navarro on 09/09/2018.
//

#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e4+5;

long long n, t, C[N], mx = -1, idx, mmc, aux;

long long  gcd(long long int a, long long b) { return b ? gcd(b, a%b) : a; }
long long mcm(long long a, long long b) { return a*b/gcd(a,b); }

int main() {

    mmc = 1;

    scanf("%lld%lld", &n, &t);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &C[i]);
        mmc = mcm(mmc, C[i]);
    }

    for(int i = 1; i <= t; i++) {
        aux = mcm(i, mmc);
        if (aux > mx && aux <= t) {
            mx = aux;
            idx = i;
        }
    }

    printf("%lld\n", idx);

return 0;
}
