//Parallel Binary Search - O(nlog^2 n + q)

struct Query{ int l, r, i, ans;};
vector<Query> req;

void pbs2(int L, int R, vector<Query> Q){
    int mid = (L+R)/2;
    // mid = (L+R+1)/2 if different from simple upper/lower bound
    if(Q.empty()) return;
    while(i < mid) {
        i++;
        //add value to data structure
    }
    while(i > mid) {
        //remove value to data structure
        i--;
    }

    if(L == R) {
        for(auto q : Q) req[q.i].ans = L;
        return;
    }

    vector<Query> vl, vr;
    for (auto q : Q) {
        if ( /* cond */ ) vl.pb(q);
        else vr.pb(q);
    }
    pbs(L, mid, vl);
    pbs(mid + 1, R, vr);
}


