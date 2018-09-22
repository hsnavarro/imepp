//
// Created by Henrique Navarro on 06/09/2018.
//

for(int i = 0; i < 9; i++){
    if(i == l) freq[i] = 1;
    else freq[i] = 0;
}

int v[N], lazy[4*N], freq[N];
vector<int> st[4*N];

void build (int p, int l, int r) {
    if (l == r) {
        for(int i = 0; i < 9; i++){
           if(i == l) freq[i] = 1;
           else freq[i] = 0;
        }
        st[p] = freq;return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}
void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}
int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    // return INF;
    // return -INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
    // return min(x, y);
    // return max(x, y);
}
void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        //increment
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) st[p] = st[2*p] + st[2*p+1];
    //st[p] = min(st[2*p], st[2*p+1]);
    //st[p] = max(st[2*p], st[2*p+1]);
}