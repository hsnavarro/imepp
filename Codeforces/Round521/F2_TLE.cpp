#include<bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
using namespace std;

typedef long long ll;

const int N = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, k, x, dp[N][N], v[N], aux, ans = -INF, s;

int main(){
    scanf("%lld%lld%lld", &n, &k, &x);
    for(int i = 0; i < n; i++) scanf("%lld", &v[i]);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = (i < k and j == 1 ? v[i] : -INF);

    for (int i = 2; i <= x; i++) {
        map<ll, ll> mp;
        for (int p = 0; p < n; p++) {
            if(mp.size()) {
                auto iter = mp.end();
                iter--;
                dp[p][i] = iter->first + v[p];
            }
            if(dp[p][i - 1] != -INF) mp[dp[p][i - 1]]++;
            if(p >= k) {
                if(dp[p - k][i - 1] != -INF) mp[dp[p - k][i - 1]]--;
                if (!mp[dp[p - k][i - 1]]) mp.erase(dp[p - k][i - 1]);
            }
        }
    }

    for (int i = n - k; i < n; i++) ans = max(ans, dp[i][x]);
    printf("%lld\n", ans == -INF ? -1 : ans);

    return 0;
}