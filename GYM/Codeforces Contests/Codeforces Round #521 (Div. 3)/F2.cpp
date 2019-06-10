#include<bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
using namespace std;

typedef long long ll;

const int N = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, k, x, dp[N][N], v[N], aux, ans = -INF, s;

struct MaxQueue {
    ll plus = 0;
    ll sz = 0;
    deque<pair<ll, ll>> dq;

    bool empty() { return dq.size() == 0; }
    void clear() { plus = 0; dq.clear(); }
    void add(ll x) { plus += x; } // Adds x to every element in the queue
    ll max() { return dq.begin()->first + plus; } // Returns the maximum element in the queue
    ll size() { return sz; }

    void push(ll x) {
        x -= plus;
        ll amt = 0;
        while (dq.size() and dq.back().first <= x)
            amt += dq.back().second + 1, dq.pop_back();
        dq.push_back({ x, amt });
        sz++;
    }

    void pop() {
        if (dq.empty()) return;
        if (!dq.front().second) dq.pop_front();
        else dq.front().second--;
        sz--;
    }
};

int main(){
    scanf("%lld%lld%lld", &n, &k, &x);
    for(int i = 0; i < n; i++) scanf("%lld", &v[i]);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = (i < k and j == 1 ? v[i] : -INF);

    for (int i = 2; i <= x; i++) {
        MaxQueue q;
        for (int p = 0; p < n; p++) {
            if(q.size() and q.max() != -INF) dp[p][i] = q.max() + v[p];
            q.push(dp[p][i - 1]);
            if(p >= k) q.pop();
        }
    }

    for (int i = n - k; i < n; i++) ans = max(ans, dp[i][x]);
    printf("%lld\n", ans == -INF ? -1 : ans);

    return 0;
}