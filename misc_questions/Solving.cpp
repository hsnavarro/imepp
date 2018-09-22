//
// Created by Henrique Navarro on 26/07/2018.
//
#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e5+5;
const int M = 2*1e9+7;

double x[N];
double y[N];

int main(){

    int n;
    double k, aux1, aux2, soma = 0, tempo;

    scanf("%d %lf", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &aux1, &aux2);
        x[i] = aux1;
        y[i] = aux2;
    }


    for (int i = 0; i < n-1; i++) {
        soma += hypot(x[i+1] - x[i], y[i+1] - y[i]);
    }

    soma = soma*k;
    tempo = soma/50;
    printf("%.9lf\n", tempo);

    return 0;

}