//
// Created by Henrique Navarro on 23/08/2018.
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e7+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int par[N], sz[N];
int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}
int main () {
    int cont = 0, a, b, w, n, m, n1, n2;
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    int cost = 0;
    vector <piii> edges;
    vector <piii> res;

   while(scanf("%d%d", &n, &m) and n) {
       for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
       cost = 0;
       edges.clear();
       res.clear();

       for (int i = 0; i < m; i++) {
           scanf("%d%d%d", &a, &b, &w);
           edges.push_back({w, {a, b}});
       }

       sort(edges.begin(), edges.end());
       for (auto e : edges)
           if (find(e.nd.st) != find(e.nd.nd)) {
               unite(e.nd.st, e.nd.nd), cost += e.st;
               res.push_back({e.st, {e.nd.st, e.nd.nd}});
           }

       printf("Teste %d\n", ++cont);
       for (int i = 0; i < res.size(); i++) {
           n1 = max(res[i].nd.st, res[i].nd.nd);
           n2 = min(res[i].nd.st, res[i].nd.nd);
           printf("%d %d\n", n2, n1);
       }
       printf("\n");
   }

return 0;
}

