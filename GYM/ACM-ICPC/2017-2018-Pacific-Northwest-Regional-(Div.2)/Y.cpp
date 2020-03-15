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

const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;

double k, p, x, ans;

int main(){
    cin >> k >> p >> x;
    double m1 = ceil(sqrt(k*p/x));
    double m2 = floor(sqrt(k*p/x));

    ans = min(m1*x + k/m1 * p, m2*x + k/m2 * p);

    printf("%.3lf\n", ans);


    return 0;
}