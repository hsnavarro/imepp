#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int M = 1e5 + 5;
const int N = 5e4 + 5;

int n, v[N], sum[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1 << n); j++){
            if((1 << i) & j) sum[j] += v[i]%(360);
            else sum[j] -= v[i]%(360);
        }
    }

    for(int j = 0; j < (1 << n); j++) if(sum[j]%(360) == 0) { printf("YES\n"); return 0; }

    printf("NO\n");
    return 0;
}