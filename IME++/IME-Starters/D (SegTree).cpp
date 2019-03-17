#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, a, b;
double v[N], st[4*N], c;

void build(int p = 1, int l = 1, int r = n){
    if(l == r) { st[p] = v[l]; return; }
    build(2*p, l, (l+r)/2), build(2*p + 1, (l+r)/2 + 1, r);
    st[p] = st[2*p] + st[2*p + 1];
}

double query(int i, int j, int p = 1, int l = 1, int r = n){
    if(l >= i and j >= r) return st[p];
    if(l > j or r < i) return 0;
    return query(i, j, 2*p, l, (l+r)/2) + query(i, j, 2*p + 1, (l+r)/2 + 1, r);
}

void update(int idx, double v, int p = 1, int l = 1, int r = n){
    if(l == r) { st[p] = v; return; }
    if(idx <= (l+r)/2) update(idx, v, 2*p, l, (l+r)/2);
    else update(idx, v, 2*p + 1, (l+r)/2 + 1, r);
    st[p] = st[2*p] + st[2*p + 1];
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf", &v[i]);
    build();
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%lf", &a, &b, &c);
        if(a == 2) printf("%lf\n", query(b, int(c))/(int(c) - b + 1));
        else update(b, c);
    }
}