#include <bits/stdc++.h>
using namespace std;

const int N = 8e6 + 5;

int n, trie[26][N], cnt = 1;
int isEnd[N];
vector<string> ans;
string a;

void insert(string s){
  int u = 1;
  for(int i = 0; i < s.size(); i++){
    char x = s[i] - 'a';
    if(trie[x][u]) u = trie[x][u];
    else trie[x][u] = ++cnt, u = cnt;
    if(i == s.size() - 1) {
      if(isEnd[u]) ans.push_back(s);
      isEnd[u]++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> a;
    if(a.size() >= 4) insert(a);
  }

  if(!ans.size()) cout << "SAFO" << "\n";
  else cout << ans.size() << "\n";
  for(auto x : ans) cout << x << "\n";
}
