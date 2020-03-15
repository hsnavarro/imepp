//
// Created by Henrique Navarro on 23/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))

using namespace std;

const int N = 1e4+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int vis[N], dp[N], n, b, t;
vector<int> adj[N];

void dfs(int x) {
   if (vis[x]) return;
    vis[x] = 1;
    for (int v : adj[x]) dfs(v);
    }


int main () {
    while(scanf("%d", &n) and n) {
    cl(dp, 0);
    for (int i = 0; i < N; i++) adj[i].clear();
        for (int j = 1; j <= n; j++){
            scanf("%d", &t);
            for (int i = 0; i < t; i++) {
                scanf("%d", &b);
                adj[j].push_back(b);
            }
        }

            for (int i = 1; i <= n; i++) {
                cl(vis, 0);
                dfs(i);
                for (int j = 1; j <= n; j++) {
                    if (vis[j]) dp[i]++;
                }
                dp[i]--;
            }

        int mx = -1;
        int idx;

            for (int i = 1; i <= n; i++) {
                if (dp[i] > mx) {
                    idx = i;
                    mx = dp[i];
                }
            }

            printf("%d\n", idx);

        }
    return 0;
}

