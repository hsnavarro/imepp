#include<bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;

int n, a;
int m[20][21][21], adj[18][18], ok[18][18], dp[(1 << 20)][20], contf[20][20];
string aux;
vector<int> res;

int cont(int i, int j){
    if(contf[i][j] != -1) return contf[i][j];
    int sum = 0;
    for(int k = 0; k < 21; k++) for(int c = 0; c < 21; c++) if(m[i][k][c] != m[j][k][c]) sum++;
    return contf[i][j] = sum;
}

void ans(int i, int j){
    res.pb(j+1);
    if(i == (1 << j)) return;
    for(int k = 0; k < n; k++) if(k != j and i & (1 << k))
            if(dp[i][j] == dp[i - (1 << j)][k] + adj[k][j]) {
                if(ok[k][j]) res.pb(0);
                ans(i - (1 << j), k);
                return;
            }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> a;
    cl(contf, -1);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 21; k++) {
            cin >> aux;
            for (int p = 0; p < 21; p++) m[i][k][p] = aux[p] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (min(cont(i, j), cont(j, 19) + a) == cont(i, j)) adj[i][j] = cont(i, j);
            else adj[i][j] = cont(j, 19) + a, ok[i][j] = 1;

            if (min(cont(j, i), cont(i, 19) + a) == cont(j, i)) adj[j][i] = cont(j, i);
            else adj[j][i] = cont(i, 19) + a, ok[j][i] = 1;
        }
    }

    cl(dp, INF);

    for (int i = 0; i < n; i++) dp[(1 << i)][i] = cont(i, 19);

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++) {
            if (i & (1 << j) and i != (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (k != j and i & (1 << k)) dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + adj[k][j]);
                }
            }
        }

    int resp = INF, j_best;
    for(int j = 0; j < n; j++) if(dp[(1 << n) - 1][j] < resp) resp = dp[(1 << n) - 1][j], j_best = j;
    ans((1 << n) - 1, j_best);
    reverse(res.begin(), res.end());

    cout << resp << endl;
    for(auto p : res) {
        if(!p) cout << '*' << endl;
        else cout << p << endl;
    }
}