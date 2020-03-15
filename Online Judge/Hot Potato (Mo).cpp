#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, SQ = 320;

int n, m, v[N], bit[N], mini[N];
vector<int> adj[N];

void dfs(int u, int r) {
    if (mini[u-1]) return;
    mini[u-1] = r;
    for(int v : adj[u]) dfs(v, r);
}

void bitadd (int p, int v) { for (p+=2; p<N; p += p&-p) bit[p] += v;}

int bitquery (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

//primeiro maior ou igual que a metade
int busc1 (int l, int r, int targ) {
    while (l != r) {
        int m = (l+r)/2;
        if (2*bitquery(m) < targ) l = m+1;
        else r = m;
    }
    return l;
}

//último menor que a metade
int busc2 (int l, int r, int targ) {
    while (l != r) {
        int m = (l+r+1)/2;
        if (2*bitquery(m) <= targ) l = m;
        else r = m-1;
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
        qs[i].l--; qs[i].r--;
    }

    sort(qs, qs + m, c1);

    for (int k = 0; k < m; ++k) {
        query &q = qs[k];
        while (r < q.r) bitadd(mini[++r], 1);
        while (l > q.l) bitadd(mini[--l], 1);
        while (r > q.r) bitadd(mini[r--], -1);
        while (l < q.l) bitadd(mini[l++], -1);


        int x = busc1 (1, n, q.r-q.l+1);
        int val1 = bitquery(x);

        int y = busc2 (1, n, q.r-q.l+1);
        int val2 = bitquery(y);

        int val = abs(2 * val1 - (q.r - q.l + 1)) < abs(2 * val2 - (q.r - q.l + 1)) ? val1 : val2;

        int i = 1;
        int j = n;
        while(i != j){
            int mid = (i + j)/2;
            int x = bitquery(mid);

            if(x < val) i = mid + 1;
            else j = mid;
        }

        q.ans = i;
    }

    sort(qs, qs + m, c2);
    for(int i = 0; i < m; i++) printf("%d\n", qs[i].ans);

    return 0;
}