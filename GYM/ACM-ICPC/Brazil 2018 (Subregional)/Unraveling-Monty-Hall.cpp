#include <bits/stdc++.h>
using namespace std;

int n, cont, aux;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        if(aux == 1) cont++;
    }

    printf("%d\n", n-cont);

    return 0;
}