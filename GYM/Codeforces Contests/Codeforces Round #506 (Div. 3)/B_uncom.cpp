//
// Created by Henrique Navarro on 08/09/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int vec[N], bit[N];

void add (int p, int v) {
    p = p-1;
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}
int query (int p) {
    int r = 0;
    for (p += 2; p; p -= p & -p) r += bit[p];
    return r;
}

int rangesum (int a, int b) {
    return query(b)-(a ? query(a-1) : 0);
}

int upper (int l, int r, int targ){
    int m;
    while(l != r){
        m = (l+r)/2;
        if(vec[m] > targ) r = m;
        else l = m + 1;
    }
    return l;
}

int main(){
    int n, mx = -INF;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vec[i]);
    }

    for(int i = 0; i < n; i++) {
        add(upper(0, n, vec[i]), 1);
    }

    for(int i = 0; i < n-1; i++) {
        if(rangesum(upper(0, n, vec[i]), upper(0, n, 2*vec[i])) > mx) mx = rangesum(upper(0, n, vec[i]), upper(0, n, 2*vec[i]));
    }

    printf("%d\n", mx);

    return 0;
}