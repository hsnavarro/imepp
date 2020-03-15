#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n, mx, mn, ans, aux;

int main() {
    scanf("%d", &n);
    int cont = n;
    while(cont--){
        scanf("%d", &aux);

        if(cont == n - 1){
            mx = aux;
            mn = aux;
        }

        if(aux > mx and cont != n - 1){ mx = aux; ans++;}
        if(aux < mn and cont != n - 1){ mn = aux; ans++;}
    }

    printf("%d\n", ans);

    return 0;
}