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

ll n, a, b, k, v[N], mx, pmx, sum;
vector<ll> aux, res;

int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        sum += v[i];
        aux.pb(v[i]);
    }
    sort(aux.begin(), aux.end());
    mx = aux[aux.size()-1];
    pmx = aux[aux.size()-2];

    for(int i = 0; i < n; i++){
        if(v[i] == mx){
            if(sum - v[i] == 2*pmx) res.pb(i);
        }
        else if(sum - v[i] == 2*mx) res.pb(i);
    }

    printf("%d\n", res.size());
    for(int i = 0; i < res.size(); i++) printf("%lld%s", res[i]+1, i == res.size()-1 ? "" : " ");

    return 0;
}