#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, a, b;
double v[N], bit[N], c;

void add(int p, double v) {
    for (p+=2; p<N; p+=p&-p) bit[p] += v;
}

double query(int p) {
    double r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

double rangesum (int a, int b) {
    return query(b)-(a ? query(a-1) : 0);
}

int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lf", &v[i]);
        add(i, v[i]);
    }
    scanf("%d", &q);

    while(q--){
        scanf(" %d %d %lf", &a, &b, &c);
        if(a == 2) printf("%lf\n", rangesum(b, int(c))/(int(c) - b + 1));
        else  add(b, c - v[b]), v[b] = c;
    }
}