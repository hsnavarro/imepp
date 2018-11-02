//
// Created by Henrique Navarro on 07/08/2018.
//

//
// Created by Henrique Navarro on 02/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int N = 1e7 + 5;
const int X = 1e9;
const int MOD = 1e9 + 7;

int long long g[N],f[N];
int n;

int main(){

    scanf("%d",&n);

    f[0] = g[0] = 1;
    f[1] = g[1] = 0;

    for(int i = 2; i<=n;i++){
        g[i] = (g[i-2] + 2*f[i-2]) % MOD;
        f[i] = (f[i-2] + g[i]) % MOD;
    }

    printf("%lld\n", g[n]);

    return 0;
}
