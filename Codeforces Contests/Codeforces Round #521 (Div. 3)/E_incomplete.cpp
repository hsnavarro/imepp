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
const int N = 2e5+5;

int n, mn = INF, c, cnt, v[N], idx;
map<int, int> cont;
vector<int> freq;

ll fexp (int b, int e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b);
        b = (b*b);
        e >>= 1;
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        cont[v[i]]++;
    }

    for(auto x : cont) freq.pb(x.nd);

    sort(freq.begin(), freq.end());
    for(int i = 0; i + 1 < freq.size(); i++) if(freq[i+1] > 2*freq[i]) idx =

                                                                               int c = 1;
    for(auto x : cont){
        cnt++;
        int p = x.nd/c;
        db(x.st _ x.nd);
        c *= 2;
        mn = min(mn, p);
    }
    db(mn);

    ll res = mn*(fexp(2, cont.size()) - 1);
    printf("%lld\n", res);

    return 0;
}