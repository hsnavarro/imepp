#include <bits/stdc++.h>
using namespace std;

const int N = 8e6;

int n, ok = 0;
set<string> s;
vector<string> ans;
char a[N];
string b;

int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%s", a);
    b = a;
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
