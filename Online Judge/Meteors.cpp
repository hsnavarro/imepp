#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5+5;

struct Query{ ll i, ans, num; };
struct rain{ ll quant, l, r; };

ll n, m, k, aux, bit[N], i = 0;
vector<Query> req;
vector<rain> chuvas;
vector<ll> adj[N];

void add(ll p, ll v) { for (p+=2; p<N; p+=p&-p) bit[p] += v; }

void update(ll l, ll r, ll val){
    if(l > r){
        add(l, val);
        add(1, val);
        add(r + 1, -val);
    }
    else {
        add(l, val);
        add(r + 1, -val);
    }
}

ll query(ll p) {
    ll r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

void pbs(ll L, ll R, vector<Query> Q){
    ll mid = (L+R)/2;
    if(L == R) for(auto q : Q) req[q.i].ans = L;
    if(Q.empty() or L == R) return;

    while(i < mid) {
        i++;
        update(chuvas[i].l, chuvas[i].r, chuvas[i].quant);
    }
    while(i > mid){
        update(chuvas[i].l, chuvas[i].r, -chuvas[i].quant);
        i--;
    }

    vector<Query> vl, vr;
    for(auto q : Q){
        if(q.i) {
            ll soma = 0;
            for (auto p : adj[q.i]) soma = min(LINF, soma + query(p));
            if (soma < q.num) vr.pb(q);
            else vl.pb(q);
        }
    }

    pbs(L, mid, vl);
    pbs(mid+1, R, vr);
}

int main(){
    scanf("%lld %lld", &n, &m);
    req.resize(n+1);

    for(ll j = 1; j <= m; j++) {
        scanf("%lld", &aux);
        adj[aux].pb(j);
    }

    for(ll j = 1; j <= n; j++){
        scanf("%lld", &req[j].num);
        req[j].i = j;
    }

    scanf("%lld", &k);
    chuvas.resize(k+6);

    for(ll j = 1; j <= k; j++) scanf("%lld %lld %lld", &chuvas[j].l, &chuvas[j].r, &chuvas[j].quant);

    pbs(1, k+5, req);

    for(auto q : req) if(q.i)
            if(q.ans <= k) printf("%lld\n", q.ans);
            else printf("NIE\n");

    return 0;
}