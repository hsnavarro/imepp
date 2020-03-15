#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 30 + 5;

int cond, n, m, cont;
int minr[N], maxb[N];
char table[N][N];
string s;
ll ans, sum, dp[N][N];

int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < N; i++) minr[i] = m + 1;

    for(int i = 1; i <= m; i++){
        cin >> s;
        for(int j = 1; j <= n; j++){
            table[i][j] = s[j-1];
            if(table[i][j] == 'B') maxb[j] = max(maxb[j], i);
            if(table[i][j] == 'R') minr[j] = min(minr[j], i);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(j < maxb[i] or j >= minr[i]) dp[i][j] = 0;
            else {
                if(i == 1) dp[i][j] = 1;
                else for(int k = j; k <= m; k++) dp[i][j] += dp[i-1][k];
            }

        }
    }

    for(int i = 0; i <= m; i++) ans += dp[n][i];

    printf("%lld\n", ans);
}