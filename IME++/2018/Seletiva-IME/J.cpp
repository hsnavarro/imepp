//
// Created by Henrique Navarro on 08/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int N = 1e6 + 5;
const int X = 1e9;
const int MOD = 1e9 + 7;

int bit[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int rangesum (int a, int b) {
    return query(b)-(a ? query(a-1) : 0);
}

int main(){
    int n, aux, i;

scanf("%d", &n);
i = n;

while(i--){
    scanf("%d", &aux);

    printf("%d\n", n - rangesum(aux,N));
    add(aux,1);
}

    return 0;
}