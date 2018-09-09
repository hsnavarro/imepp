//
// Created by Henrique Navarro on 28/08/2018.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5, M = 6e5, SQ = 708 + 5;
int n, m, v[N], cont[M], bloc[SQ], res, cond;

void add(int x) {
    if(cont[x] == 1) bloc[x/SQ]--;
    cont[x]++;
    if(cont[x] == 1) bloc[x/SQ]++;
}
void rem(int x) {
    if(cont[x] == 1) bloc[x/SQ]--;
   cont[x]--;
    if(cont[x] == 1) bloc[x/SQ]++;
}

struct query { int i, l, r, ans; } qs[N];

bool c1(query a, query b) {
    if(a.l/SQ != b.l/SQ) return a.l < b.l;
    return a.l/SQ&1 ? a.r > b.r : a.r < b.r;
}

bool c2(query a, query b) { return a.i < b.i; }

int main() {
    int l = 0, r = -1;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        qs[i].i = i;
        qs[i].ans = 0;
        scanf("%d %d", &qs[i].l, &qs[i].r);
        qs[i].l--;
        qs[i].r--;
    }

    sort(qs, qs + m, c1);
    for (int i = 0; i < m; ++i) {
        query &q = qs[i];
        while (r < q.r) add(v[++r]);
        while (l > q.l) add(v[--l]);
        while (r > q.r) rem(v[r--]);
        while (l < q.l) rem(v[l++]);

        res = 0;
        cond = 0;

        for(int i = 0; i < SQ; i++){
            if(bloc[i]){
                for(int j = i*SQ; j < i*SQ + SQ; j++){
                    if(cont[j] == 1){
                        res = j; cond = 1; break;
                    }
                }
            }
            if(cond) break;
        }

        q.ans = res;
    }

   sort(qs, qs + m, c2);
    for(int i = 0; i < m; i++){
        printf("%d\n", qs[i].ans);
    }

    return 0;
}
