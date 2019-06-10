//
// Created by Henrique Navarro on 10/09/2018.
//

#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int N = 1e6+10; // Upper limit to n

long long res(long long n){
    long long ans = 0;
for(long long i = 2; i*i <= n; i++) {
if (n % i == 0) ans++;
while (n % i == 0) n = n / i;
}
return ans + (n > 1);
}



int main () {
    long long n, resp, cont;

    scanf("%lld", &n);
    cont = res(n);

    resp = (1ll << cont) - 1 - cont;
    printf("%lld\n", resp);

    return 0;
}