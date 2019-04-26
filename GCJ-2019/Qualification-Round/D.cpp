#include <bits/stdc++.h>
using namespace std;

int t, n, b, f;
string s, aux, a;
vector<string> num;
vector<int> ans, res;

int btoi (string &a){
  int ans = 0;
  for(int i = 0; i < 4; i++) ans += (a[i] - '0')*(1 << i);
  return ans;
}

void reset(){ num.clear(), ans.clear(), res.clear(); }


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    reset();
    cin >> n >> b >> f;

    for(int i = 0; i < 4; i++){
      aux.clear();
      for(int j = 0; j < n; j++) aux += '0' + ((j >> i) % 2);
      cout << aux << endl;
      cin >> s;
      num.push_back(s);
    }

    for(int i = 0; i < n - b; i++){
      a.clear();
      for(int j = 0; j < 4; j++) a += num[j][i];
      ans.push_back(btoi(a));
    }

    for(int i = 0, idx = 0; i < n; i++){ 
      if(idx == ans.size() or (i % 16) != ans[idx]) res.push_back(i);
      else idx++;
    }

    for(auto x : res) cout << x << " ";
    cout << endl;

    cin >> f;
  }
}


