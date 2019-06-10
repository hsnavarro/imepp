#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define nd second
#define st first

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll la, ra, ta;
ll lb, rb, tb;
ll l, r;
ll mdc;

int main(){
    scanf("%d %d %d", &la, &ra, &ta);
    scanf("%d %d %d", &lb, &rb, &tb);

    mdc = gcd(ta, tb);

    lb *= ta/mdc;
    rb *= ta/mdc;

    la *= tb/mdc;
    ra *= tb/mdc;

    l = max(la, lb);
    r = min(ra, rb);

    ll ans = r - l +1;
    if(ans < 0) ans = 0;
    printf("%lld\n", ans);

    return 0;
}