//
// Created by Henrique Navarro on 23/08/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int X = 1e9;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1e6+10;

int vis[N];
vector<int> adj[N];
int m, n, aux, ans = INF, cont, x, y;

void dfs(int x) {
    vis[x] = 1;
    for (int v : adj[x]) if (!vis[v]) dfs(v);
}

int main() {
int aux, nl;
set<int> s;
    scanf("%d", &n);
    nl = n;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        s.insert(x);


        adj[x].push_back(y+1000);
        adj[y+1000].push_back(x);
    }

    for(int i = 1; i <= 1000; i++){
        if(!vis[i]){
            dfs(i);
            //db(i);
        }
        else cont++;
    }
    //db(cont);
    cont = s.size() - cont;
    //db(cont);

    printf("%d\n", cont - 1);

    return 0;
}