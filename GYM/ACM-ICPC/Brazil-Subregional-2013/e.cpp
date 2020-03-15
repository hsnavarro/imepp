#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, k, a;
set<int> s;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n >> k){
    s.clear();
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 1; i <= k; i++) cin >> a, s.erase(a);
    if(!s.size()) cout << "*\n";
    else {
      for(auto x : s) cout << x << " ";
      cout << "\n";
    }
  }
} 
