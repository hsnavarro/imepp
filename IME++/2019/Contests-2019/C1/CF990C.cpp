#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

#define int long long

int n, sum;
pair<int, int> mp[N];
string s;

void go(string s){
  int l = 0, r = 0;
  for(auto p : s){
    if(p == ')') !l ? r++ : l--;
    else l++;
  }
  
  if(l and r) return;
  if(l or r) l ? mp[l].first++ : mp[r].second++;
  else mp[l].first++, mp[r].second++;
}

int32_t main(){
  cin >> n;
  while(n--) cin >> s,  go(s);
  for(int i = 0; i < N; i++) sum += mp[i].first*mp[i].second;
  cout << sum << endl;
}
