#include <bits/stdc++.h>
using namespace std;

int x, y, h, v, a1, a2;
vector<pair<int, int>> hor, ver;

const int N = 1e5+10; // Vector size

int bit[N][N];
void add (int x, int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[x][p] += v;
}
int query (int x, int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[x][p];
    return r;
}

int rangesum (int x, int a, int b) {
    return query(x, b)-(a ? query(x, a-1) : 0);
}

int main(){
    scanf("%d%d", &x, &y);
    scanf("%d%d", &h, &v);

    for(int i = 0; i < h; i++){
        scanf("%d%d", &a1, &a2);
        hor.push_back(make_pair(a1, a2));
    }

    for(int i = 0; i < v; i++){
        scanf("%d%d", &a1, &a2);
        ver.push_back(make_pair(a1, a2));
    }



    return 0;
}