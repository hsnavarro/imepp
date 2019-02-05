#include<bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
using namespace std;

typedef long long ll;

const int N = 205;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, k, x, dp[N][N], v[N], aux, ans = -INF;

int main(){
    scanf("%lld%lld%lld", &n, &k, &x);
    for(int i = 0; i < n; i++) scanf("%lld", &v[i]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dp[i][j] = (i < k and j == 1 ? v[i] : -INF);

    for (int i = 1; i <= x; i++)
        for(int p = 0; p < n; p++)
            for (int j = max(0ll, p - k); j < p; j++) if(dp[j][i-1] != -INF) dp[p][i] = max(dp[p][i], dp[j][i - 1] + v[p]);

    for (int i = n - k; i < n; i++) ans = max(ans, dp[i][x]);
    printf("%lld\n", ans == -INF ? -1 : ans);

    return 0;
}