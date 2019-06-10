//
// Created by Henrique Navarro on 28/08/2018.
//
//
// Created by Henrique Navarro on 23/08/2018.
//

//
// Created by Henrique Navarro on 23/08/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int X = 1e9;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int M = 1e6+4;

// Square Root Decomposition (Mo's Algorithm) - O(n^(3/2))
const int N = 2e5+1, SQ = 500;
int n, m, v[N], cont[M];
unsigned long long S, aux;

void add(int x) {
    // aux = cont[x]*cont[x]*x;
    S += 2*x*cont[x] + x;
    cont[x]++;
    //S += cont[x]*cont[x]*x - aux;
}
void rem(int x) {
   if(!cont[x]) return;
    //aux = cont[x]*cont[x]*x;
    S += x - 2*x*cont[x];
    cont[x]--;
    //S += cont[x]*cont[x]*x - aux;
}

struct query {
    int i, l, r;
    long long ans;
} qs[N];

bool c1(query a, query b) {
    if(a.l/SQ != b.l/SQ) return a.l < b.l;
    return a.l/SQ&1 ? a.r > b.r : a.r < b.r;
}

bool c2(query a, query b) { return a.i < b.i; }

int main() {
    int l = 0, r = -1;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    for (int i = 0; i < m; i++) {
        qs[i].i = i;
        qs[i].ans = 0;
        scanf("%d %d", &qs[i].l, &qs[i].r);
        qs[i].l--;
        qs[i].r--;
    }
    S = 0;

    sort(qs, qs + m, c1);
    for (int i = 0; i < m; ++i) {
        query &q = qs[i];
        while (r < q.r) add(v[++r]);
        while (l > q.l) add(v[--l]);
        while (r > q.r) rem(v[r--]);
        while (l < q.l) rem(v[l++]);

        q.ans = S;
    }

    sort(qs, qs + m, c2); // sort to original order
    for(int i = 0; i < m; i++){
        printf("%I64d\n", qs[i].ans);
    }

    return 0;
}
