#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 15;

char a[N], b[N];
int pl_a, pl_b, var;

int fat(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n*fat(n-1);
}

float ans(int n, int k){
    float comb = fat(n)/(fat(k)*(fat(n-k)));
    return comb * pow(0.5, n);
}


int main(){
    fgets(a, N, stdin);
    fgets(b, N, stdin);

    int m = strlen(a);

    for(int i = 0; i < m; i++){
        if(a[i] == '+') pl_a++;
        if(b[i] == '+') pl_b++;
        if(b[i] == '?') var++;
    }

    float res;
    if(var == 0 and pl_a != pl_b) res = 0.0;
    else if(var < (pl_a - pl_b)) res = 0.0;
    else if((pl_a - pl_b) < 0) res = 0.0;
    else res = ans(var, pl_a-pl_b);

    printf("%.12lf\n", res);

    return 0;
}
