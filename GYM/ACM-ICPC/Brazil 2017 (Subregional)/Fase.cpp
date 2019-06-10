//
// Created by Henrique Navarro on 09/09/2018.
//

#include <bits/stdc++.h>
using namespace std;

int n, k, cont[1001], aux, aux2;

int main(){

    scanf("%d", &n);
    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &aux2);
        cont[aux2]++;
    }

    for(int i = 1000; i >= 0; i--){
        aux += cont[i];
        if(k - aux <= 0) break;
    }

    printf("%d\n", aux);






    return 0;
}