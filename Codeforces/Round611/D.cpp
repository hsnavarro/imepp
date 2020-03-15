#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

int n, k, a;
long long dist;
vector<int> v, ans;
pair<int, int> aux;
set<pair<int, int>> lf, rg;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a, v.pb(a);
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++){
    int tl = INF, tr = INF;
    if(i-1 >= 0) tl = (v[i] - v[i-1])/2;
    if(i+1 < n) tr = (v[i+1] - v[i] - 1)/2;
    lf.insert({v[i], tl});
    rg.insert({v[i], tr});
  }

  for(int cnt = 1; cnt < INF; cnt++){
    if(ans.size() == k) break;
    for(auto it = lf.begin(); it != lf.end() and ans.size() != k; ){
      aux = *it;
      it++;
      if(cnt > aux.nd) lf.erase(aux);
      else ans.pb(aux.st - cnt), dist += 1ll*cnt;
    }

    for(auto it = rg.begin(); it != rg.end() and ans.size() != k; ){
      aux = *it;
      it++;
      if(cnt > aux.nd) rg.erase(aux);
      else ans.pb(aux.st + cnt), dist += 1ll*cnt;
    }
  }

  cout << dist << "\n";
  for(auto x : ans) cout << x << " ";
  cout << "\n";

}
