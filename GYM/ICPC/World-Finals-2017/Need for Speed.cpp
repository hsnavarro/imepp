#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const int M = 1e6+1005;

double n, t, d[N], s[N],mx = -1001.0;

double func2(double* d, double* s, double c){
    double sm = 0.0;
    for (int i = 0; i < N; i++) sm += d[i]/(s[i]+c);
    return sm;
}

double upper (double l, double r, double targ) {
    for (int i = 0; i < 50; i++) {
        double m = (l+r)/2;
        if (func2(d, s, m) > targ) l = m;
        else r = m;
    }
    return l;
}

int main(){

    scanf("%lf %lf", &n, &t);
    for(int i = 0; i < n; i++){
        scanf("%lf %lf", &d[i], &s[i]);
        if(-s[i] > mx) mx = -s[i];
    }

    double ans = upper(mx,M,t);

    printf("%.9lf\n", ans);

    return 0;
}