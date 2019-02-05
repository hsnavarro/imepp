#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1e3 + 5;

int par[N], sz[N], res[N], n, cost, aux, vis[N];
vector<piii> edges;
vector<int> adj[N];

void dfs(int u = 1) {
    vis[u] = 1;
    for(auto x : adj[u]) if(!vis[x]) {
            res[x] = u;
            dfs(x);
        }
}

int find(int a){ return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b){
    if(find(a) == find(b)) return;
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], par[b] = a;
}

int main(){
    for(int i = 0; i < N; i++) sz[i] = 1, par[i] = i;

    scanf("%d", &n);
    for(int j = 2; j <= n; j++){
        for(int i = 1; i < j; i++){
            scanf("%d", &aux);
            edges.pb({-aux, {i, j}});
            edges.pb({-aux, {j, i}});
        }
    }

    sort(edges.begin(), edges.end());
    for(auto e : edges) if(find(e.nd.st) != find(e.nd.nd)){
            cost += e.st, unite(e.nd.st, e.nd.nd);
            adj[e.nd.st].pb(e.nd.nd);
            adj[e.nd.nd].pb(e.nd.st);
        }

    printf("%d\n", -cost);
    dfs();


    for(int i = 2; i <= n; i++) printf("%d\n", res[i]);


    return 0;
}