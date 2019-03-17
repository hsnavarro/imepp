#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 1e5 + 5;

int n, m, a, b;
vector<int> adj[N];
int dp[N][2];

int dpf(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    if(adj[i].empty()){
        if(j) return dp[i][j] = 1;
        return dp[i][j] = 0;
    }

    int ans = 0;
    for(auto p: adj[i]){
        if(j) ans += dpf(p, 0);
        else ans += max(dpf(p, 0), dpf(p, 1));
    }

    return dp[i][j] = j ? ans + 1 : ans;
}

int main(){
    cl(dp, -1);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
    }

    int res = max(dpf(1, 0), dpf(1, 1));

    printf("%d\n", res);

    return 0;
}