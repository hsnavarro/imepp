#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;

int dis = INF, ax, ay, bx, by, cx, cy, resx, resy, table[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pii par[N][N], in = {INF, INF};
queue<pii> q;
vector<pii> ans;

bool check(int x, int y){
    if(x < 0 or x > 1000 or y < 0 or y > 1000) return false;
    return true;
}

void bfs(int x, int y, int px, int py){
    par[x][y] = {px, py};
    q.push({x, y});
    while(!q.empty()) {
        int ux = q.front().st;
        int uy = q.front().nd;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (par[ux + dx[i]][uy + dy[i]] == in and check(ux + dx[i], uy + dy[i])) {
                par[ux + dx[i]][uy + dy[i]] = {ux, uy};
                q.push({ux + dx[i], uy + dy[i]});
            }
        }
    }
}

void search(int x, int y){
    if(x != resx or y != resy){
        table[x][y] = 1;
        pii u = par[x][y];
        search(u.st, u.nd);
    }
}

int dist(int ax, int ay, int bx, int by){ return abs(ax - bx) + abs(ay - by); }

int main(){

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) par[i][j] = in;

    scanf("%d%d", &ax, &ay);
    scanf("%d%d", &bx, &by);
    scanf("%d%d", &cx, &cy);

    for(int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            if (dist(i, j, ax, ay) + dist(i, j, bx, by) + dist(i, j, cx, cy) < dis) {
                dis = dist(i, j, ax, ay) + dist(i, j, bx, by) + dist(i, j, cx, cy);
                resx = i, resy = j;
            }

    ans.pb({resx, resy});
    bfs(resx, resy, -1, -1);
    pii aux = par[1][0];
    search(ax, ay), search(bx, by), search(cx, cy);

    for(int i = 0; i <= 1000; i++) for (int j = 0; j <= 1000; j++) if(table[i][j]) ans.pb({i, j});

    printf("%d\n", ans.size());
    for(auto u : ans) printf("%d %d\n", u.st, u.nd);


}