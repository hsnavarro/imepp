#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

const int N = 1e5+5;

struct Query{ int l, r, i, vall, valnl, ans, val;};

int n, m, i, seq, v[N], bit[N], mini[N];
vector<int> adj[N], adj2[N];
vector<Query> req, aux;

void dfs(int u, int r) {
    if (mini[u]) return;
    mini[u] = r;
    for(int v : adj[u]) dfs(v, r);
}

void add(int p, int v) { for (p+=2; p<N; p+=p&-p) bit[p] += v; }

int query(int p) {
    int r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

void pbs(int L, int R, vector<Query> Q, int isLower){
    int mid = (L + R + !isLower)/2;
    if(Q.empty()) return;

    while(i < mid) for (auto p : adj2[++i]) add(p, 1);
    while(i > mid) for(auto p : adj2[i--]) add(p, -1);

    if(L == R) {
        for(auto q : Q) {
            if(isLower) req[q.i].vall = query(q.r) - query(q.l - 1);
            else req[q.i].valnl = query(q.r) - query(q.l - 1);
        }
        return;
    }

    if(isLower) {
        vector<Query> vl, vr;
        for (auto q : Q) {
            if (2*(query(q.r) - query(q.l - 1)) >= (q.r - q.l + 1)) vl.pb(q);
            else vr.pb(q);
        }
        pbs(L, mid, vl, 1);
        pbs(mid + 1, R, vr, 1);
    }
    else {
        vector<Query> vl, vr;
        for (auto q : Q) {
            if (2*(query(q.r) - query(q.l - 1)) >= (q.r - q.l + 1)) vl.pb(q);
            else vr.pb(q);
        }
        pbs(L, mid-1, vl, 0);
        pbs(mid, R, vr, 0);
    }
}

void pbs2(int L, int R, vector<Query> Q){
    int mid = (L+R)/2;
    if(Q.empty()) return;

    while(i < mid) for (auto p : adj2[++i]) add(p, 1);
    while(i > mid) for(auto p : adj2[i--]) add(p, -1);

    if(L == R) {
        for(auto q : Q) req[q.i].ans = L;
        return;
    }

    vector<Query> vl, vr;
    for (auto q : Q) {
        if ((query(q.r) - query(q.l - 1)) >= q.val) vl.pb(q);
        else vr.pb(q);
    }
    pbs2(L, mid, vl);
    pbs2(mid + 1, R, vr);
}


int main() {

    scanf("%d%d", &n, &m);
    req.resize(m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        adj[v[i]].pb(i);
        dfs(i, i);
    }

    for (int i = 0; i < m; i++) {
        req[i].i = i;
        scanf("%d%d", &req[i].l, &req[i].r);
    }

    for (int i = 1; i <= n; i++) adj2[mini[i]].pb(i);

    pbs(1, 1e5, req, 1);
    pbs(1, 1e5, req, 0);

    for(auto x : req){
        seq = (x.r - x.l + 1);
        x.val = abs(2*x.vall - seq) < abs(2*x.valnl - seq) ? x.vall : x.valnl;
        aux.pb(x);
    }

    pbs2(1, 1e5, aux);
    for(auto x : req) printf("%d\n", x.ans);

    return 0;
}
