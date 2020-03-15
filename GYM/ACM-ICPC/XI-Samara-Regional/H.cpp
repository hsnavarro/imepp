#includebitsstdc++.h
#define db(x) cerr  #x   ==   x  endl
#define _  ,  
#define cl(x, v) memset((x), (v), sizeof(x))
#define st first
#define nd second
using namespace std;

typedef long long ll;
typedef vectorint vi;
typedef pairint, int pii;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int vis[N], dist[N], n, m, d, s, f;
char table[N];
queueint q;

bool check(int x) { return x = 0 and x = nm; }

void bfs1(){
    int dir[] = {-1, 1, -m, m};
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(dist[u] = d) continue;
        for (int i = 0; i  4; i++) {
            if((u+1)%m == 0 and i == 1) continue;
            if((u)%m == 0 and i == 0) continue;
            int x = u + dir[i];
            db(dir[i]);
            db(u _ x _ m);
            if(!check(x)) continue;
            if(!vis[x]){
                table[x] = 'x';
                dist[x] = dist[u] + 1;
                vis[x] = 1;
                q.push(x);
            }
        }
    }

}


void bfs2(int s){
    int dir[] = {-1, 1, -m, m};
    cl(dist, 63);
    cl(vis, 0);
    vis[s] = 1;
    dist[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i  4; i++) {
            int x = u + dir[i];
            if((u+1)%m == 0 and i == 1) continue;
            if((u)%m == 0 and i == 0) continue;
            if(table[x] == 'x' or !check(x)) continue;
            if(!vis[x]){
                dist[x] = dist[u] + 1;
                vis[x] = 1;
                q.push(x);
            }
        }
    }

}



int main(){
    cl(dist, 63);
    scanf(%d%d%d, &n, &m, &d);
    for(int i = 0; i  nm; i++){
            scanf( %c, &table[i]);
            if(table[i] == 'S') s = i;
            if(table[i] == 'F') f = i;
            if(table[i] == 'M') {vis[i] = 1; dist[i] = 0; q.push(i); table[i] = 'x'; }
    }
    for(int i = 0; i  nm; i++) printf(%c%s, table[i], (i+1)%m == 0  n   );

    bfs1();
    for(int i = 0; i  nm; i++) printf(%c%s, table[i], (i+1)%m == 0  n   );

    if(table[s] == 'x') printf(-1n);
    else{
        bfs2(s);
        printf(%dn, dist[f] == INF  -1  dist[f]);
    }

    return 0;
}