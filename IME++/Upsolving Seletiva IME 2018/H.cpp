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

double n, a, p, res;

scanf("%lf %lf %lf", &n, &a, &p);
p = p/100.0;
res = n + a*p - a*(1-p);

printf("%.9lf\n", res);



    return 0;
}


