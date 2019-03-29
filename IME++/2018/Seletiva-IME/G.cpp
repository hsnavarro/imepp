#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1000 + 5;
const int M = 2e5 + 5;
const int NUM = 5e5 + 5;

int cmp[N], n, t, sz, v[M], a;
vector<int> prim;
bool ok[M];
ll res;
int mp[NUM];

void sieve(){
    for(int i = 2; i < N; i++) if(!cmp[i])
            for(int j = i*i; j < N; j+= i) cmp[j] = 1;

    for(int i = 2; i < N; i++) if(!cmp[i]) prim.pb(i);
}

void add(int n, bool e){
    vector<int> p;
    for(int i = 0; prim[i]*prim[i] <= n; i++){
        if(!(n%prim[i])) p.pb(prim[i]);
        while(!(n%prim[i])) n /= prim[i];
    }
    if(n > 1) p.pb(n);

    int aux, c, cnt = 0;
    for(int j = 1; j < (1 << (p.size())); j++) {;
        aux = 1, c = 0;
        for (int i = 0; i < p.size(); i++) if ((1 << i) & j) aux *= p[i], c++;
        if(!e) mp[aux]--;
        if (c & 1) cnt += mp[aux];
        else cnt -= mp[aux];
        if(e) mp[aux]++;
    }
    res += e ? sz - cnt : -(sz - 1 - cnt);
}

int main(){
    scanf("%d%d", &n, &t);
    sieve();
    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
    while(t--){
        scanf("%d", &a);
        add(v[a], !ok[a]);
        ok[a] ? sz-- : sz++, ok[a] = !ok[a];

        printf("%lld\n", res);
    }
}