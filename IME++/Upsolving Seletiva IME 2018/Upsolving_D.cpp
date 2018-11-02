//
// Created by Henrique Navarro on 08/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int N = 1e7 + 5;
const int X = 1e9;
const int MOD = 1e9 + 7;

int main(){

    int n;
    double a, res;

    scanf("%d", &n);

    while(n--) {

        scanf("%lf", &a);

        res = (-1 + sqrt(1 + 8 * a)) / 2;

        printf("%d\n", int(res));
    }

    return 0;
}

