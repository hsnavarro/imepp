#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

string s;
vector<ll> p;
ll n, q, k;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  
  cin >> q;

  while(q--){
    p.clear();
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < s.size(); i++) if(s[i] == '0') p.push_back(i);
    
    int cnt = 0;
    for(auto &x : p){
      if(k >= x - cnt) k -= (x - cnt), x = cnt, cnt++;
      else x -= k, k = 0;
    }

    for(auto &x : s) x = '1';
    for(auto x : p) s[x] = '0';
    cout << s << "\n";
  }
  

}
