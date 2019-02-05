//Persistent Segment Tree
//Update and Query - O(log n)
//Space - O(n log n)

//M -> n log n

int nxt;
int lc[M], rc[M], st[M];
vector<int> root;

int update(int n, int l, int r, int idx, int v){
    if(l == r) { st[nxt] = v; return nxt++; }
    int mid = (l+r)/2;
    int u = nxt++;
    if(i <= mid){
        lc[u] = update(lc[n], l, mid, idx, v);
        rc[u] = rc[n];
    }else{
        rc[u] = update(rc[n], mid, r, idx, v);
        lc[u] = lc[n];
    }
    st[u] = st[lc[u]] + st[rc[u]]; // RMQ -> min/max, RSQ -> +
    return u;
}

int query(int n, int l, int r, int i, int j){
    if(i > r or l > j) return 0;
    if(i <= l and j >= r) return st[n];
    return query(lc[n], l, (l+r)/2, i, j) + query(rc[n], (l+r)/2 + 1, r, i, j); // RMQ -> min/max, RSQ -> +
}