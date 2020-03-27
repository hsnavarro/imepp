#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 5000 + 5;

pii cod[N];
vector<pii> adj[N], res;
int n, m, k, s, t, a, b, c, d, sum, vis[N];
vector<int> tst;
set<int> num;

bool in(int k, pii a){ return k >= a.st and k <= a.nd; }

void dfs(int k, int x = s){
    vis[x] = 1;
    for(auto p : adj[x]) if(!vis[p.st] and in(k, cod[p.nd])) dfs(k, p.st);
}

int main(){
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(!num.count(c)) tst.pb(c), num.insert(c);
        if(!num.count(d + 1)) tst.pb(d + 1), num.insert(d + 1);
        adj[a].pb({b, i});
        cod[i] = {c, d};
    }

    sort(tst.begin(), tst.end());

    for(int i = 0; i < tst.size(); i++){
        cl(vis, 0), dfs(tst[i]);
        if(vis[t]) res.pb({tst[i], tst[i+1] - 1});
    }

    for(auto p : res) sum += p.nd - p.st + 1;
    printf("%d\n", sum);
}