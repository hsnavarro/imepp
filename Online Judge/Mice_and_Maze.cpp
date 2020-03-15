//
// Created by Henrique Navarro on 23/08/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e4+10; // Maximum number of nodes
int dist[N];
vector <pair<int,int>> adj[N];
priority_queue <pair<int,int>> pq;
int a, b, w, m, n;
void dijkstra (int s) {
    // Be careful with directed graphs!
    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int ud = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int cont, e, t;

int main(){

    scanf("%d", &n);
    scanf("%d", &e);
    scanf("%d", &t);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[b].push_back({a, w});
    }
    dijkstra(e);
    for(int i = 1; i <= n; i++){
        if(dist[i] <= t) cont++;
    }

    printf("%d", cont);

    return 0;
}