//
// Created by Henrique Navarro on 10/09/2018.
//

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const int MOD = 1e9 + 7;

const int N = 1e5+10; // Maximum number of nodes
int vis[N], din[N], c, n, a, b, w, cost;
vector<pii> adj[N];

void dfs(int x) {
    vis[x] = 1;

    for (int v : adj[x]){

        int u = v.st
        if (!vis[u]) dfs(u);
    }
}



int main(){
    scanf("%d%d", &n, &c);

    for(int i = 0; i < n; i++)
        scanf("%d", &din[i]);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }













    return 0;
}