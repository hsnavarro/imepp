#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back

typedef long long ll;

const int N = 5e5 + 5;

int n, s, f, a, b;
vector<int> adj[N];

int main(){
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 1; i <= n; i++) if(adj[i].size() == 1) f++;

    printf("%.12lf\n", 2*double(s)/f);
}