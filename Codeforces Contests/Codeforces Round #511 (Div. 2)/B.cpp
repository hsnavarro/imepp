#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, SQ = 320;

int n, x, y, aux, mx = -1;

int main() {

    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &x, &y);
        aux = x+y;
        if(aux > mx) mx = aux;
    }

    printf("%d\n", mx);




    return 0;
}
