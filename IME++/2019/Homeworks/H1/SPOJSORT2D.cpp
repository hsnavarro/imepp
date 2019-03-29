#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
  if(a.first > b.first or (a.first == b.first and a.second < b.second)) return false;
  return true;
}

int main(){
  scanf("%d", &t);
  while(t--){
    v.clear();
    scanf("%d", &n);
    v.resize(n);
    for(int i = 0; i < n; i++) scanf("%d%d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end(), cmp);
    for(auto x : v) printf("%d %d\n", x.first, x.second); 
  }
}
