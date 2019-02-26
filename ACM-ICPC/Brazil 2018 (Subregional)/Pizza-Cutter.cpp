#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

long long inv;
int x, y, h, v, a, b;
vector<pair<int, int>> v1, v2, ans;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.nd == b.nd and a.st < b.st) return true;
    if(a.nd < b.nd) return true;
    return false;
}

void mergesort(vector<pair<int, int>> &v, int l, int r){
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

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> x >> y;
    cin >> h >> v;
    ans.resize(h);
    for(int i = 0; i < h; i++){
        cin >> a >> b;
        v1.push_back({a, b});
    }
    for(int i = 0; i < v; i++){
        cin >> a >> b;
        v2.push_back({a, b});
    }

    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);

    mergesort(v1, 0, h-1);
    ans.clear(), ans.resize(v);
    mergesort(v2, 0, v-1);

    cout << 1ll*(h+1)*(v+1) + inv << endl;
}