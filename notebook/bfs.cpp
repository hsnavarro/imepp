// Breadth First Search O(V+E)

const int N = 1e5 + 5;

int vis[N];
vi adj[N];
queue<int> q;

void bfs(int x){
    vis[x] = 1;
    q.push(x);
    while(!q.empty){
        int u = q.front(); q.pop();
        for(auto u : adj[x]) if(!vis[u]){
            vis[u] = 1;
            q.push(u);
        }
    }
}