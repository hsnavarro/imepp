#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n, v[N], sum[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < (1 << n); j++) ((1 << i) & j) ? sum[j] += v[i]%(360) : sum[j] -= v[i]%(360);

    for(int j = 0; j < (1 << n); j++) if(!(sum[j]%(360))) { printf("YES\n"); return 0; }
    printf("NO\n");
}