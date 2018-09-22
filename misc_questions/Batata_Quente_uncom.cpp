#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e5+5, SQ = 320;

int n, m, mn, v[N], bit[N], vis[N], mini[N];
vector<int> adj[N];

void dfs(int u, int mn) {
    if (vis[u]) return;
    vis[u] = 1; mini[u-1] = mn;
    for (int v : adj[u]) dfs(v, mn);
}

void bitadd (int p, int v) { for (p+=2; p<N; p += p&-p) bit[p] += v; }
int bitquery (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int uppe (int l, int r, int targ) {
    while (l != r) {
        int m = (l+r+1)/2;
        if (mini[m] >= targ) r = m-1;
        else l = m;
    }
    return (mini[l] < targ) ? mini[l] : -1;
}

int upper (int l, int r, int targ) {
    while (l != r) {
        int m = (l+r)/2;
        if (bitquery(m) > targ) r = m;
        else l = m+1;
    }
    return l;
}

int busc3 (int l, int r, int targ) {
    while (l != r) {
        int m = (l+r)/2;
        if (bitquery(m) < targ) l = m+1;
        else r = m;
    }
    return l;
}

struct query { int i, l, r, ans; } qs[N];

bool c1(query a, query b) {
    if(a.l/SQ != b.l/SQ) return a.l < b.l;
    return a.l/SQ&1 ? a.r > b.r : a.r < b.r;
}

bool c2(query a, query b) { return a.i < b.i; }

int main() {
    int l = 0, r = -1;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        adj[v[i]].push_back(i+1);
    }

    for(int i = 1; i <= n; i++) dfs(i,i);

    for (int i = 0; i < m; i++) {
        qs[i].i = i;
        qs[i].ans = 0;
        scanf("%d %d", &qs[i].l, &qs[i].r);
        qs[i].l--;
        qs[i].r--;
    }

    sort(qs, qs + m, c1);
    for (int i = 0; i < m; ++i) {
        query &q = qs[i];
        while (r < q.r) bitadd(mini[++r], 1);
        while (l > q.l) bitadd(mini[--l], 1);
        while (r > q.r) bitadd(mini[r--], -1);
        while (l < q.l) bitadd(mini[l++], -1);

        int x = upper(0,N,(q.r-q.l+1)/2);
        int val1 = bitquery(x);
        //db(x);
        int y = uppe(q.l, q.r, x);
        int val2 = bitquery(y);
        //db(y);

        int val = abs(2 * val1 - (q.r - q.l + 1)) < abs(2 * val2 - (q.r - q.l + 1)) ? val1 : val2;

        int z = busc3 (1, n, val);

        q.ans = z;
    }

    sort(qs, qs + m, c2);
    for(int i = 0; i < m; i++) printf("%d\n", qs[i].ans);

    return 0;
}