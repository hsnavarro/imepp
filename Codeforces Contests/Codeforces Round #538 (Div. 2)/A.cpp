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

int x, y, z, a, b, c;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if(a >= x) {
        a -= x;
    }
    else {cout << "NO" << endl; return 0; }
    if( a + b >= y){
        int aux = min(a, y);
        a -= aux;
        y -= aux;
        int aux2 = min(b, y);
        b -= aux2;
    }
    else {cout << "NO" << endl; return 0; }
    if(a + b + c >= z) { cout << "YES" << endl; return 0;}
    else {cout << "NO" << endl; return 0; }


}