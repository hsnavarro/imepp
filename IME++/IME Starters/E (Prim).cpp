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

vector<pii> adj[N];
int cost, vis[N], par[N];
priority_queue<piii> pq;
int n, aux;

void process(int u, int ud, int p){
    par[u] = p;
    vis[u] = 1;
    cost += ud;
    for(auto x : adj[u]){
        int v = x.st;
        int w = x.nd;
        if(!vis[v]) pq.push({-w, {v, u}});
    }
}

void prim(int s = 1){
    pq.push({0, {s, 0}});
    while(!pq.empty()){
        int ud = -pq.top().st;
        int u = pq.top().nd.st;
        int p = pq.top().nd.nd;
        pq.pop();
        if(vis[u]) continue;
        process(u, ud, p);
    }
}


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            scanf("%d", &aux);
            adj[i].pb({j, -aux});
            adj[j].pb({i, -aux});
        }
    }

    prim();

    printf("%d\n", -cost);
    for(int i = 2; i <= n; i++) printf("%d\n", par[i]);
}