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

ll n, k, freq[N], aux;
vector<ll> ans, v;

bool cmp(ll a, ll b){ return (freq[a] > freq[b]); }

bool test(ll x){
    ll cont = 0;
    for(auto p : v) cont += freq[p]/x;
    if(cont >= k) return true;
    return false;
}

ll bin(ll l, ll r){
    ll mid;
    while(l < r){
        mid = (l+r+1)/2;
        if(!test(mid)) r = mid-1;
        else l = mid;
    }
    return r;
}

int main(){
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &aux);
        if(!freq[aux]) v.pb(aux);
        freq[aux]++;
    }

    sort(v.begin(), v.end(), cmp);
    int res = bin(1, n);

    for(int i = 0; i < v.size(); i++){
        ll rep = freq[v[i]]/res;
        while(rep-- and ans.size() != k) ans.pb(v[i]);
        if(ans.size() == k) break;
    }

    for(auto x : ans) printf("%lld ", x);

    return 0;
}