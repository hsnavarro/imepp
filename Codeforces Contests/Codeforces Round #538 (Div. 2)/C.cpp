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

ll n, b, mn = LINF;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> b;
    for(ll i = 2; i*i <= b; i++){
        if(b % i == 0){
            ll cont = 0;
            while(b % i == 0) b /= i, cont++;
            ll aux = n/i;
            ll sum = 0;
            while(aux) sum += aux, aux /= i;
            mn = min(mn, sum/cont);
        }
    }

    if(b > 1) {
        ll aux = n/b;
        ll sum = 0;
        while(aux) sum += aux, aux /= b;
        mn = min(mn, sum);
    }

    cout << mn << endl;
}