#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

#define st first
#define nd second

int n, m, v[N], sum, adj[N][N], adjw[N][N];
vector<pair<int, int>> p;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        p.push_back({v[i], i});
    }

    int a, b;
    while(m--){
        cin >> a >> b;
        adj[a][b] = v[b];
        adj[b][a] = v[a];
    }

    sort(p.begin(), p.end(), greater<pair<int, int>> ());
    for(auto x : p){
        for(int i = 1; i <= n; i++){
            sum += adj[x.nd][i];
            adj[x.nd][i] = 0;
            adj[i][x.nd] = 0;
        }
    }

    cout << sum << endl;
}
