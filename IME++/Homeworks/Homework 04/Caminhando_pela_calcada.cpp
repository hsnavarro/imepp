#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, A, B, C, D, cont, t;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){

    scanf("%d", &t);

    while(t--) {
        scanf("%d%d%d%d", &A, &B, &C, &D);
        a = min(A, C);
        b = min(B, D);
        c = max(A, C);
        d = max(B, D);

        cont = gcd(c-a, d-b) + 1;

        printf("%d\n", cont);
    }

    return 0;

}

