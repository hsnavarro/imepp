#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const ll N = 1e6;
const int INF = 0x3f3f3f3f;

ll sum, a, b;

void res(ll a, ll b) {
    for (ll x = 1; x <= N; x++)
        for (ll y = (a + x - 1)/x * x; y <= b; y += x)
            if (y / x >= x) sum += x + (x*x != y ? y/x : 0);
}

int main(){
    cin >> a >> b;
    res(a, b);
    cout << sum << endl;
}