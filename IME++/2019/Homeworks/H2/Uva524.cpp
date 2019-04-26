#include<bits/stdc++.h>
using namespace std;

int n, cnt, pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
set<int> p, used;
vector<int> ans;

void bt(int x){
  if(x == n){
    if(p.count(ans.back() + 1)){
    for(auto p : ans) (p != ans.back() ? cout << p << " " : cout << p);
    cout << endl;
    }
    return;
  }

  for(int i = 2; i <= n; i++)
    if(p.count(i + ans.back()) and !used.count(i)) 
      ans.push_back(i), used.insert(i), bt(x+1), ans.pop_back(), used.erase(i);
}

int main(){
  while(~scanf("%d", &n) and ++cnt){
    ans.clear();
    for(int i = 0; i < 11; i++) p.insert(pri[i]);
    if(cnt != 1) printf("\n");
    ans.push_back(1);
    printf("Case %d:\n", cnt);
    bt(1);
  }
}
