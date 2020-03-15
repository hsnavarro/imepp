#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
int n, cnt, a, ult;
vector<int> v;
set<int> s;
map<int, int> last_idx;

ll fexp (ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % mod;
        b = (b*b) % mod;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a, v.pb(a), last_idx[a] = i;

    int i = 0;
    while (i < v.size()) {
        cnt++, ult = last_idx[v[i]];
        while (i < ult) i++, ult = max(ult, last_idx[v[i]]);
        i++;
    }

    cout << fexp(2, cnt - 1, MOD) << endl;
}