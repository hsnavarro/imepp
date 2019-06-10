//
// Created by Henrique Navarro on 21/09/2018.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n, num[N], mdc, mdc2, k;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
    scanf("%d", &n);
   // k = n;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        mdc = gcd(mdc, num[i]);
    }

    for(int i = 0; i < n; i++){
        if(gcd(mdc2, num[i]) > mdc){
            mdc2 = gcd(mdc2, num[i]);
            k++;
        }
    }

    if(k == 0){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", n-k);






}

