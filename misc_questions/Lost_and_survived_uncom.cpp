//
// Created by Henrique Navarro on 24/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<

using namespace std;

const int N = 1e5+5;

int par[N], sz[N], aux[N];
int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}
int main () {
    int n, q, a, b;
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &a, &b);
        unite(a, b);

        for (int j = 1; j <= n; j++) {
            aux[j] = sz[find(j)];
        }
        sort(aux, aux+n+1);
       printf("%d\n", abs(aux[n] - aux[1]));
    }
    return 0;
}

