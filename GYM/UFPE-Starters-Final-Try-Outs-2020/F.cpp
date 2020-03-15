#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

int n;
ll l[N], r[N], h[N];
set<pair<ll, int>> s;
// h, idx
vector<pair<int, pair<int, int>> > act;
// l or r, if is l or r, idx

ll get_max(){
  auto it = s.end();
  it--;
  return (*it).first;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i] >> r[i] >> h[i];
    act.push_back({l[i], {1, i}});
    act.push_back({r[i], {-1, i}});
  }

  ll sum = 0;
  sort(act.begin(), act.end());
  for(int i = 0; i < act.size(); i++){
    if(i and s.size()) sum += (act[i].first - act[i-1].first)*get_max();
    int idx = act[i].second.second;
    if(act[i].second.first == 1){
      s.insert({h[idx], idx});
    } else {
      s.erase({h[idx], idx});
    }
  }
  cout << sum << endl;
}
