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

double p[7], maxp = -2.00, sum;
vector<int> maxi;


double esp(){
    double ans = 0.0;
    for(int i = 1; i <= 6; i++) ans += i*p[i];

    return ans;
}

double par(){
    double ans = 0.0;
    int ok = 0;
    for(int i = 1; i <= 6; i++) {
        if(p[i] == maxp and !ok) continue;
        ans += i*p[i];
    }
    return ans;
}

int main(){
    for(int i = 1; i <= 6; i++) {
        scanf("%lf", &p[i]);
        if(p[i] > maxp) maxp = p[i];
    }

    for(int i = 1; i <= 6; i++) if(p[i] == maxp) maxi.pb(i);

    double res = (3.5 - par())/maxp;

    for(auto p : maxi) sum += double(p);

    printf("%.3lf\n", abs(res - sum));


    return 0;
}