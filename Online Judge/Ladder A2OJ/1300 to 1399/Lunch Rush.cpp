#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n, k, t, f, ans = -INF, aux;

int main() {
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%d %d", &f, &t);
        if(t > k) aux = f - (t - k);
        else aux = f;

        if(aux > ans) ans = aux;
    }
    printf("%d\n", ans);

    return 0;
}