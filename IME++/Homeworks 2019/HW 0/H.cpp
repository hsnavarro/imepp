#include <bits/stdc++.h>
using namespace std;

int n, m, mn = 0x3f3f3f3f;
vector<int> v;

int main(){
    cin >> n >> m;
    v.resize(m);
    for(int i = 0; i < m; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i + n <= m; i++) mn = min(mn, v[n+i-1] - v[i]);
    cout << mn << endl;
}
