//
// Created by Henrique Navarro on 08/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

const int N = 1e5 + 5;



int par[N], sz[N], n, m, aux1, aux2, cont;
vector<int> seq, res;
pair<int, int> a[N];
int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    cont--;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}


int main(){
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    scanf("%d %d", &n, &m);
    cont = n;

    for(int i=0; i<m; i++){
        scanf("%d %d", &aux1, &aux2);
        a[i] = make_pair(aux1, aux2);
    }

    for(int i=0; i<m; i++){
        scanf("%d", &aux1);
        seq.push_back(aux1);
    }

    reverse(seq.begin(), seq.end());

    for(int i=0; i<m; i++) {
        res.push_back(cont);
        unite(a[seq[i] - 1].first, a[seq[i] - 1].second);
    }
    reverse(res.begin(), res.end());
    for(int i=0; i<m; i++){
        printf("%d\n", res[i]);
    }



    return 0;
}