#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

ll l, r, n, m, a;
vector<ll> o, s;
ll bit1[N], bit2[N];

void add1(int p, ll v) {
    for (p+=2; p<N; p+=p&-p) bit1[p] += v;
}

ll query1(int p) {
    ll r = 0;
    for (p+=2; p; p-=p&-p) r += bit1[p];
    return r;
}

void add2(int p, ll v) {
    for (p+=2; p<N; p+=p&-p) bit2[p] += v;
}

ll query2(int p) {
    ll r = 0;
    for (p+=2; p; p-=p&-p) r += bit2[p];
    return r;
}


int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    scanf("%lld", &n);
    while(n--) scanf("%lld", &a), o.pb(a);
    s = o;
    sort(s.begin(), s.end());

    for(int i = 0; i < o.size(); i++) add1(i, o[i]);
    for(int i = 0; i < o.size(); i++) add2(i, s[i]);

    scanf("%lld", &m);
    while(m--){
        scanf("%lld%lld%lld", &a, &l, &r);
        l --, r--;
        if(a == 1) printf("%lld\n", query1(r) - (l ? query1(l-1) : 0));
        else printf("%lld\n", query2(r) - (l ? query2(l-1) : 0));
    }
}