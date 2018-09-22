//
// Created by Henrique Navarro on 05/09/2018.
//

//
// Created by Henrique Navarro on 05/09/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e5+5;
int n, res, vec[N], cont[N], bit[N];

void bitadd (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}
int bitquery (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int upper (int l, int r, int targ) {
    int m;
    while (l != r) {
        m = (l+r)/2;
        if (bitquery(m) > targ) r = m;
        else l = m+1;
    }
    return l;
}

int main() {
    int l = 0, r = -1, m, S;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &vec[i]);
    }

    for(int i = 0; i < n; i++){
        cont[vec[i]]++;
    }

    for(int i = 0; i < N; i++) {
        bitadd(i, cont[i]);
    }

    res = upper(0,N-1,n/2);

    printf("%d", res);



    return 0;
}