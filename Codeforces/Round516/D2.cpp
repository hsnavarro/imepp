#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define st first
#define nd second
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int N = 2000 + 5;

char aux, table[N][N];
int dir[N][N], dist[N][N];
int lt, rt, m, n, r, c;
deque <piii> dq;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void zero_one_bfs (int i, int j){
    cl(dist, 63);
    dist[i][j] = 0;
    dq.push_back({{i, j}, 0});
    while(!dq.empty()){
        int u = dq.front().st.st;
        int h = dq.front().st.nd;
        int ud = dq.front().nd;
        dq.pop_front();
        if(dist[u][h] < ud) continue;
        for(int z = 0; z < 4; z++){
            int x = u + dx[z];
            int y = h + dy[z];
            if (table[x][y] == 'x' or table[x][y] == '*') continue;
            int w;
            if(z == 1) w = 1;
            else w = 0;
            if(dist[u][h] + w < dist[x][y]){
                dist[x][y] = dist[u][h] + w;
                if(w) dq.push_back({{x, y}, dist[x][y]});
                else dq.push_front({{x, y}, dist[x][y]});
            }
        }
    }
}


int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &r, &c);
    scanf("%d%d", &lt, &rt);

    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            if(i != 0 and j != 0 and i != n+1 and j != m+1) {
                scanf(" %c", &aux);
                table[i][j] = aux;
            }
            else table[i][j] = 'x';
        }
    }

    zero_one_bfs(r, c);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dir[i][j] = dist[i][j] + j - c;
            if (dist[i][j] <= lt and dir[i][j] <= rt) ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
