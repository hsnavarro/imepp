#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define nd second
#define st first

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int vis[N];
int n, s, a[N], b[N], u;
vector<int> adj[N];

void dfs(int x){
    vis[x] = 1;
    for(auto u : adj[x]) if(!vis[u]) dfs(u);
}

int main(){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    int cont = 0;
    for(int i = 0; i < n; i++){
        if(a[i] and cont) {
            adj[u].push_back(i);
            u = i;
        }
        if(a[i] and !cont) {
            u = i; cont = 1;
        }
    }
    cont = 0;
    for(int i = n-1; i >= 0; i--){
        if(b[i] and cont) {
            adj[u].push_back(i);
            u = i;
        }
        if(b[i] and !cont) { u = i; cont = 1; }
    }

    dfs(0);
    printf("%s\n", vis[s-1] ? "YES" : "NO");

    return 0;
}