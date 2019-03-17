#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))

typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef pair<ld, pii> T;

const int N = 1e6+10;

int par[N], sz[N], n;
ld a, b, cost;
ld x[N], y[N];
vector<T> edges;


int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

int main () {
    while(~scanf("%d", &n) and n){

        cost = 0.0;
        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
        edges.clear();

        for (int i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &y[i]);

        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                ld dx = x[i] - x[j];
                ld dy = y[i] - y[j];
                ld dist = sqrt(dx*dx + dy*dy);
                edges.pb({dist,{i, j}});
            }
        }

        sort(edges.begin(), edges.end());
        for (auto e : edges) {
            if (find(e.nd.st) != find(e.nd.nd)) {
                unite(e.nd.st, e.nd.nd);
                cost = max(cost, e.st);
            }
        }

        printf("%.4lf\n", cost);



    }

    return 0;
}