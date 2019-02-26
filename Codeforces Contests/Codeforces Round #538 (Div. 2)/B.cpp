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

vector<pair<ll, int>> aux;
ll v[N], sum, n, m, k;
int ok[N];
vector<int> idx, ans;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i], aux.pb({v[i], -i});
    }

    sort(aux.begin(), aux.end());
    int ab = m*k;
    while(ab--){
        idx.pb(-aux.back().nd);
        sum += aux.back().st;
        aux.pop_back();
    }

    for(auto p : idx) ok[p] = 1;

    int cont = 0;
    for(int i = 0; i < n; i++){
        if(ok[i]) cont++;
        if(cont == m) {
            ans.pb(i+1);
            cont = 0;
        }
        if(ans.size() == k - 1) break;
    }

    cout << sum << endl;
    for(auto p : ans) cout << p << " ";
    cout << endl;





}
