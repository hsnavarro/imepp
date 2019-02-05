#include<bits/stdc++.h>
using namespace std;

int n, c, z, aux;


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &aux);
        if(aux == 0) z++;
        if(aux == 5) c++;
    }

    c = c/9 * 9;
    if(!z) printf("-1");
    else if(!c) printf("0");
    else {
        for (int i = 0; i < c; i++) printf("5");
        for (int i = 0; i < z; i++) printf("0");
    }

    return 0;
}