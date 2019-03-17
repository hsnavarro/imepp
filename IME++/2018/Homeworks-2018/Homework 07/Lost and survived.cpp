#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N], sz[N];
set<pair<int, int>> g;
int n, q, a, b;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}
int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) g.insert(make_pair(1 , i));

    while(q--){
        scanf("%d%d", &a, &b);
        g.erase(make_pair(sz[find(a)],find(a)));
        g.erase(make_pair(sz[find(b)],find(b)));
        unite(a,b);
        g.insert(make_pair(sz[find(a)],find(a)));

        printf("%d\n", (*g.rbegin()).first - (*g.begin()).first);
    }
    return 0;
}