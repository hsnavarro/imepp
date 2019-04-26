#include <bits/stdc++.h>
using namespace std;

int t, n;
long long inv;
vector<int> v, ans;

void mergesort(vector<int> &v, int l, int r){
    if(l == r) return;
    int mid = (l+r)/2, i = l, j = mid + 1, k = l;
    mergesort(v, l, mid), mergesort(v, mid+1, r);
    while(i <= mid and j <= r){
        if(v[i] > v[j]) ans[k++] = v[j++], inv += j-k;
        else ans[k++] = v[i++];
    }
    while(i <= mid) ans[k++] = v[i++];
    for(i = l; i < k; i++) v[i] = ans[i];
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    inv = 0;
    v.clear(), v.resize(n), ans.clear(), ans.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    mergesort(v, 0, v.size() - 1);
    cout << inv << endl;
  }
}
