#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> s;
vector<string> ans;
string b;


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> b;
    if(b.size() >= 4) {
      if(s.count(b)) ans.push_back(b);
      else s.insert(b);
    }
  }
  if(!ans.size()) printf("SAFO\n");
  else {
    printf("%d\n", int(ans.size()));
    for(auto x : ans) printf("%s\n", x.c_str());
  }
}
