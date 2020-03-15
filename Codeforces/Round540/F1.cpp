#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 3e5 + 5;

int n, cnt, r, b;
int vis[N], cor[N];
vector<int> adj[N];
pair<int, int> est[N];

//red - blue

void dfs(int x){
    vis[x] = 1;
    for(auto v : adj[x]) if(!vis[v]) dfs(v);
    for(auto v : adj[x]) {
        est[x].first += est[v].first;
        est[x].second += est[v].second;
    }
    if(cor[x] == 1) est[x].first++;
    if(cor[x] == 2) est[x].second++;
}

bool check(int r, int b){
    return ((!r and b) or (r and !b) or (!r and !b));
}

void dfs2(int x){
    vis[x] = 1;
    for(auto v : adj[x]) if(!vis[v]) {
            if(check(r - est[v].first, b - est[v].second) and check(est[v].first, est[v].second)) cnt++;
            dfs2(v);
        }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cor[i];
        if(cor[i] == 1) r++;
        if(cor[i] == 2) b++;
    }
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //red - blue
    dfs(1);
    cl(vis, 0);
    //cout << endl;
    dfs2(1);
    //for(int i = 1; i <= n; i++) cout << est[i].first << " " << est[i].second << endl;
    cout << cnt << endl;


}