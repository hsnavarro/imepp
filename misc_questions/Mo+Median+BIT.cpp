//
// Created by Henrique Navarro on 28/08/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int X = 1e9;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int M = 1e5+5;

// Square Root Decomposition (Mo's Algorithm) - O(n^(3/2))
const int N = 1e5+5, SQ = 400;
int n, m, v[N], cont[N], bit[N], vis[N], mini[N], mn;
vector<int> adj[N];
int dfs(int x) {
    vis[x] = 1;
    for (int v : adj[x]) {
        if (!vis[v]) {
            return min(min(v,x),dfs(v));
        }
    }
}
void bitadd (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}
int bitquery (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int upper (int l, int r, int targ) {
    int m;
    while (l != r) {
        m = (l+r)/2;
        if (bitquery(m) > targ) r = m;
        else l = m+1;
    }
    return l;
}

int uppe (int l, int r, int targ) {
    int cond = targ;
    targ = targ/2;
    int m;
    while (l != r) {
        m = (l+r+1)/2;
        if (bitquery(m) > targ) r = m-1;
        else l = m;
    }
    return l;
}

void add(int x) {
    cont[x]++;
}
void rem(int x) {
    cont[x]--;
}

struct query {
    int i, l, r;
    long long ans;
} qs[N];

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
    }


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
        while (r < q.r) add(v[++r]);
        while (l > q.l) add(v[--l]);
        while (r > q.r) rem(v[r--]);
        while (l < q.l) rem(v[l++]);

        cl(bit,0);

        for(int j = 0; j < N; j++){
            bitadd(j, cont[j]);
        }

       // if((q.r-q.l+1)&1) q.ans = upper(0,N-1,(q.r-q.l+1)/2);
       // else q.ans = uppe(0,N-1,(q.r-q.l+1)/2) + 1;
      q.ans = uppe(0,N-1,(q.r-q.l+1)/2);
    }

    sort(qs, qs + m, c2);
    for(int i = 0; i < m; i++){
        printf("%d\n", qs[i].ans);
    }
    return 0;
}
//
// Created by Henrique Navarro on 06/09/2018.
//

