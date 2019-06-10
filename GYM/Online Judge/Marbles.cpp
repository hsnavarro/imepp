#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

ll a, b, x, y, d, k, n, t, c1, c2;

//x = t*x0 + k*b/gcd(a,b)
//y = t*y0 - k*a/gcd(a,b)
//t = d/mdc(a,b)

void ext_euc(ll a, ll b, ll &x, ll &y, ll &d){
    if(b) ext_euc(b, a%b, y, x, d), y -= (a/b)*x;
    else x = 1, y = 0, d = a;
}


int main(){
    while(scanf("%lld", &n) and n){
        scanf("%lld %lld", &c1, &a);
        scanf("%lld %lld", &c2, &b);

        ext_euc(a, b, x, y, d);
        t = n/d;
        if(c1*b - c2*a >= 0){
            if((-t*x)/(b/d) >= 0) k = (-t*x + (b/d) - 1)/(b/d);
            else k = (-t*x)/(b/d);
        }
        else {
            if((t*y)/(a/d) >= 0) k = (t*y)/(a/d);
            else k = (t*y - (a/d) + 1)/(a/d);
        }

        x = t*x + k*(b/d);
        y = t*y - k*(a/d);

        if(!(n%d) and x >=0 and y >= 0) printf("%lld %lld\n", x, y);
        else printf("failed\n");
    }

    return 0;
}