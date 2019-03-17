#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define int long long

int n, m;
vector<int> a;
vector<pair<int, int>> b;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  b.resize(m);
  for(int i = 0; i < m; i++) cin >> b[i].st >> b[i].nd;
  // larg - alt
  for(auto box : b){
    int t = max(a[0], a[box.st-1]);
    cout << t << endl;
    a[0] = t + box.nd;  
  }
}
