#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, cnt;
int a[N], sp[N], si[N];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    si[0] = sp[0] = 0;
    si[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(i & 1) si[i] += si[i-1] + a[i], sp[i] += sp[i-1];
        else sp[i] += sp[i-1] + a[i], si[i] += si[i-1];
    }

    for(int i = 1; i <= n; i++){
        int valp = sp[i] + si[n] - si[i-1];
        int vali = si[i] + sp[n] - sp[i-1];
        if(valp == vali) cnt++;
    }

    cout << cnt << endl;
}