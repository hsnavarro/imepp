#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int price[25][25], m, c, n, dp[250][25], aux;

int dpf(int mon, int obj){
    if(dp[mon][obj] != -1) return dp[mon][obj];
    if(obj == c) return mon;
    int ans = -1;
    for(int i = 0; i < 25; i++) if (price[obj][i] and mon + price[obj][i] <= m) ans = max(ans, dpf(mon + price[obj][i],obj + 1));
    return dp[mon][obj] = ans;
}

int main(){
    scanf("%d", &n);
    while(n--){
        cl(dp, -1);
        cl(price, 0);
        scanf("%d %d", &m, &c);
        for(int i = 0; i < c; i++){
            scanf("%d", &aux);
            for(int j = 0; j < aux; j++) scanf("%d", &price[i][j]);
        }
        int res = dpf(0, 0);
        if(res == -1) printf("no solution\n");
        else printf("%d\n", res);
    }

    return 0;
}