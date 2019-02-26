// Ternary Search - O(log n)

int ternary_search_min (int l = 1, int r = N){
    int m1, m2, mid, mn = INF, idx;
    while(r - l > 5){
        mid = (l+r)/2;
        m1 = mid;
        m2 = mid + 1;
        if(func(m2) < func(m1)) l = m1;
        else r = m2;
    }
    for(int i = l; i <= r; i++) if(func(i) < mn) mn = func(i), idx = i;
    return idx;
}

int ternary_search_max (int l = 1, int r = N){
    int m1, m2, mid, mx = -INF, idx;
    while(r - l > 5){
        mid = (l+r)/2;
        m1 = mid;
        m2 = mid + 1;
        if(func(m2) > func(m1)) l = m1;
        else r = m2;
    }
    for(int i = l; i <= r; i++) if(func(i) > mx) mx = func(i), idx = i;
    return idx;
}