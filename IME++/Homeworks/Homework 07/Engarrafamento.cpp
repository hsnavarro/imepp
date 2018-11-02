#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define cl(x, v) memset((x), (v), sizeof(x))

typedef pair<int,int> pii;
typedef long long ll;

const int N = 300 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dist[N];
vector <pair<ll, ll>> adj[N];
priority_queue <pair<ll, ll>> pq;
ll a, b, w, m, n, s, d;
void dijkstra (ll s) {
    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.st;
            ll w = x.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v],v));
            }
        }
    }
}

int main () {
    while(scanf("%lld %lld", &n, &m) and n){
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            scanf("%lld %lld %lld", &a, &b, &w);
            adj[a].pb({b, w});
        }

        scanf("%lld %lld", &s, &d);
        dijkstra(s);

        printf("%lld\n", dist[d] == INF ? -1 : dist[d]);
    }


    return 0;
}