#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, l, r, ok[N], cnt[N], idx = 1;
vector<int> v;
queue<int> t;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    v.resize(n+m);
    for(int i = 0; i < n+m; i++) cin >> v[i];
    for(int i = 0; i < n+m; i++) {
        cin >> ok[i];
        if (ok[i]) t.push(v[i]);
    }
    l = t.front(); t.pop();
    if(t.size()) r = t.front(), t.pop();
    else r = INF;
    for(int i = 0; i < n+m; i++){
        if(v[i] >= r and t.size()) l = r, r = t.front(), t.pop(), idx++;
        if(!ok[i]) (abs(r - v[i]) < abs(l - v[i]) and r != INF) ? cnt[idx+1]++ : cnt[idx]++;
    }
    for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
    cout << endl;
}