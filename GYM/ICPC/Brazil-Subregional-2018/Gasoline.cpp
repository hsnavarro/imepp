#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 2e4+5, INF = 0x3f3f3f3f;
struct edge {int v, c, f;};
struct edge_ori {int u, v, t;};

int n, src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<edge_ori> total_edgs;

vector<int> g[N];

void add_edge (int u, int v, int c) {
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

bool bfs() {
    memset(h, 0, sizeof h);
    queue<int> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

int dfs (int u, int flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1) continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

int p, r, c, d[N], e[N], u, v, t, tgt, ans;

int dinic (int x) {

    edgs.clear();
    for(int i = 0; i < N; i++) g[i].clear();

    for(int i = 1; i <= r; i++) add_edge(src, i, e[i]);
    for(int i = 1; i <= p; i++) add_edge(i+1000, snk, d[i]);

    for(int i = 0; i < c; i++){
        if(total_edgs[i].t <= x) add_edge(total_edgs[i].u, total_edgs[i].v, INF);
    }

    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

int bin_search(int l, int r, int target){
    int mid;
    while(l != r){
        mid = (l+r)/2;
        if(dinic(mid) < target) l = mid+1;
        else r = mid;
    }
    return l;
}

int main(){
    scanf("%d %d %d", &p, &r, &c);

    for(int i = 1; i <= p; i++) {
        scanf("%d", &d[i]);
        tgt += d[i];
    }

    for(int i = 1; i <= r; i++) scanf("%d", &e[i]);
    for(int i = 0; i < c; i++){
        scanf("%d %d %d", &u, &v, &t);
        total_edgs.push_back({v, u+1000, t});
    }

    src = 0;
    snk = 5000;

    ans = bin_search(0, 1e6+5, tgt);
    printf("%d\n", ans == 1e6+5 ? -1 : ans);


}



