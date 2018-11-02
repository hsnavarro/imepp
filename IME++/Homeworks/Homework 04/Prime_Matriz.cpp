#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

typedef long long ll;

const int N = 505;
const int M = 1e6+5;
const int INF = 0x3f3f3f3f;

int n, m, mx[N][N], ans = INF;

int cmp[M];
set<int> p;

void primes() {
    for (ll i = 2; i < M; ++i)
        if (!cmp[i]) {
            for (ll j = i * i; j < M; j += i) cmp[j] = 1;
            p.insert(i);
        }
}


int main(){

    primes();

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mx[i][j]);

    for(int i = 0; i < n; i++){
        int cont = 0;
        for(int j = 0; j < m; j++){
            int aux = mx[i][j];
            while(!p.count(aux)){
                aux++; cont++;
            }
        }
        ans = min(ans, cont);
    }

    for(int j = 0; j < m; j++){
        int cont = 0;
        for(int i = 0; i < n; i++){
            int aux = mx[i][j];
            while(!p.count(aux)){
                aux++; cont++;
            }
        }
        ans = min(ans, cont);
    }

    printf("%d\n", ans);
    return 0;
}


