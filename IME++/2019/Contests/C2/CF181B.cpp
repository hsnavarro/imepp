#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

int n, x, y, ans;
vector<pii> v;

bool can(pii a, pii b){
  if(((a.st + b.st) & 1) or ((a.nd + b.nd) & 1)) return false;
  return true;
}

pii mid(pii a, pii b){ return { (a.st+b.st)/2, (a.nd+b.nd)/2 }; }

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> x >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++){
    for(int j = i + 2; j < v.size(); j++){
      if(!can(v[i], v[j])) continue;
      int low = lower_bound(v.begin(), v.end(), mid(v[i], v[j])) - v.begin();
      if(v[low] == mid(v[i], v[j])) ans++;
    }
  }

  cout << ans << endl;
}
