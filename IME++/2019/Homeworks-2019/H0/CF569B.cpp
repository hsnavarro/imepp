#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, vis[N], vis2[N];
set<int> s;
auto it = s.begin();
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) s.insert(i);
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < v.size(); i++) if(v[i] <= n and !vis2[v[i]]) s.erase(v[i]), vis[i]++, vis2[v[i]]++;
    for(int i = 0; i < v.size(); i++) if(!vis[i]) it = s.begin(), v[i] = *it, s.erase(*it);
    for(auto x : v) cout << x << " ";
    cout << endl;
}