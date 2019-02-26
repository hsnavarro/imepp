// Merge-sort with inversion count - O(nlog n)

int n, inv;
vector<int> v, ans;

void mergesort(vector<int> &v, int l, int r){
    if(l == r) return;
    int mid = (l+r)/2;
    mergesort(v, l, mid), mergesort(v, mid+1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid and j <= r){
        if(v[i] > v[j]){
            ans[k++] = v[j++];
            inv += j-k;
        }
        else ans[k++] = v[i++];
    }
    while(i <= mid) ans[k++] = v[i++];
    for(i = l; i < k; i++) v[i] = ans[i];
}

//in main
ans.resize(n);

