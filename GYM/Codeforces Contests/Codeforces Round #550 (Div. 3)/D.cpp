#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int N = 2e5+5;

int n, v[N], freq[N];
pair<int, int> mx = {-1, -1};
vector<pair<int, pair<int, int>>> ans;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> v[i], freq[v[i]]++;

  for(int i = 1; i <= n; i++)
    if(freq[v[i]] > freq[mx.st]) mx.st = v[i], mx.nd = i;

  for(int i = mx.nd; i-1 >= 1; i--){
    if(v[i-1] < mx.st) ans.pb({1, {i-1, i}});
    if(v[i-1] > mx.st) ans.pb({2, {i-1, i}});
  }

  for(int i = mx.nd; i + 1 <= n; i++){
    if(v[i+1] < mx.st) ans.pb({1, {i+1, i}});
    if(v[i+1] > mx.st) ans.pb({2, {i+1, i}});
  }
  cout << ans.size() << endl;
  for(auto x : ans) cout << x.st << " " << x.nd.st << " " << x.nd.nd << endl;
}
