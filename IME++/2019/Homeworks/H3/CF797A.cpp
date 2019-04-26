#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e5+5;
const int INF = 0x3f3f3f3f;

int n, k;
int f[M], ans[20+5];

void prime(int n){ for(int i = 2; i*i < M; i++) while(!(n%i)) n /= i, f[i]++; }

int main(){
    scanf("%d%d", &n, &k);
    int cont = 0, mult = 1;
    prime(n);
    for(int i = 0; i < M; i++) 
      while(f[i]-- and cont != k-1) ans[cont++] = i, mult *= i;  

    ans[cont] = n/mult;

    if(cont != k-1 or ans[cont] == 1) return printf("-1\n"), 0;
    for(int i = 0; i < k; i++) printf("%d ", ans[i]);
    printf("\n");
}  
