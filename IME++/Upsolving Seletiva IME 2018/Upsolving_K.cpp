//
// Created by Henrique Navarro on 09/08/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const int N = 1e5+5; // Maximum number of nodes
int dist[N][3];
vector <pii> adj[N];
priority_queue <piii> pq;


int a, b, w, m, n;
void dijkstra (int s) {
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    cl(dist, 63);
    dist[s][0] = 0;
    pq.push({0, {s, 0}});
    while (!pq.empty()) {
        int ud = -pq.top().st;
        int md = pq.top().nd.nd;
        int u = pq.top().nd.st; pq.pop();
        if (dist[u][md] < ud or u == n) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int w = x.nd;
            if (dist[v][(md+1)%3] > dist[u][md] + w) {
                dist[v][(md+1)%3] = dist[u][md] + w;
                pq.push({-dist[v][(md+1)%3],{v,(md+1)%3}});
            }
        }
    }
}

vector<pair<int, string>> aux;

int main(){
    scanf("%d %d", &n, &m);
    dijkstra(1);



        aux.pb(mp(dist[n][0], "me"));
        aux.pb(mp(dist[n][1], "Gon"));
        aux.pb(mp(dist[n][2], "Killua"));
        //db(dist[3*n]);
        //db(dist[3*n+1]);
        //db(dist[3*n+2]);

    sort(aux.begin(), aux.end());

    for(int i = 0; i< 3; i++){
        cout << aux[i].second << endl;
    }

    //dist[3*n] You
    //dist[3*n+1] Gon
    //dist[3*n+2] Killua
}