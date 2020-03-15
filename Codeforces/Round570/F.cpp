#include <bits/stdc++.h>
using namespace std;

int q, n, a;
set<int> s;
vector<int> rem;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    s.clear();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a, s.insert(a);
    int mx = *s.rbegin(), ans1 = 0, ans2 = mx, cnt = 0;
    if(mx % 30 == 0 and s.count(mx/3) and s.count(mx/5) and s.count(mx/2))
      ans1 = mx/3 + mx/5 + mx/2;
    
    while(s.size() and cnt++ != 2){
      rem.clear();
      for(auto x : s) if(mx % x == 0) rem.push_back(x);
      for(auto x : rem) s.erase(x);
      if(s.size()) mx = *s.rbegin(), ans2 += mx;
    }
    
    cout << max(ans1, ans2) << "\n";
  }
}
