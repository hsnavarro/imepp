#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back

typedef long long ll;

const int N = 2e5 + 5;

int n, n1, n2, a[N];
ll sum[N], res, ans;
vector<int> adj[N];

void dfs(int u = 1, int p = -1, int h = 0){
    res += 1ll*h*a[u], sum[u] = a[u];
    for(auto x : adj[u]){
        if(x == p) continue;
        dfs(x, u, h + 1);
        sum[u] += sum[x];
    }
}

void dfs2(int u = 1, int p = -1){
    ans = max(ans, res);
    for(auto x : adj[u]){
        if(x == p) continue;
        sum[u] -= sum[x], res += sum[u] - sum[x], sum[x] += sum[u];
        dfs2(x, u);
        sum[x] -= sum[u], res -= sum[u] - sum[x], sum[u] += sum[x];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &n1, &n2);
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }

    dfs(), dfs2();
    printf("%lld\n", ans);
}