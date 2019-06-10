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

double x, v, t, vx, vy, sumd, sumvd, a, b, c;
int n, cond;

int main(){
    scanf("%d%lf%lf", &n, &x, &v);
    while(n--){
        scanf("%lf%lf%lf", &a, &b, &c);
        sumvd += c*(b - a);
    }

    vy = sumvd/(-x);
    if(v*v - vy*vy < 0) cond = 1;
    else vx = sqrt(v*v - vy*vy), t = x/vx;


    if(t > 2*x/v or cond) printf("Too hard\n");
    else printf("%.3lf\n", t);
}