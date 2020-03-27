#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

bitset<N> b;
vector<bitset<N>> s;

int n, m, aux, aux2, cont;

int main(){

    scanf("%d%d", &n, &m);

    s.resize(n);

    scanf("%d", &aux);
    while(aux--){
        scanf("%d", &aux2);
        b.flip(aux2);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &aux);
        while (aux--) {
            scanf("%d", &aux2);
            s[i].flip(aux2);
        }
    }

    for(int j = 1; j <= 2; j++) {
        for (int i = 0; i < n; i++) {
            b = b ^ s[i];
            cont++;
            if(j == 2 and i == n-1) {
                printf("-1");
                return 0;
            }
            if(b == 0) {
                printf("%d", cont);
                return 0;
            }
        }
    }

    return 0;
}

