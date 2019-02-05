#include <bits/stdc++.h>
using namespace std;

int n, res, aux, s;

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &aux);
        s += aux;
        if(s < res) res = s;
    }

    printf("%d\n", abs(res));

    return 0;
}