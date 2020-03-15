#include <bits/stdc++.h>
using namespace std;

int n;
multiset<string> s[2];
string a;

void mount() {
  string ans;
  for(auto x : s[1]) s[0].erase(s[0].find(x));
  vector<string> aux;
  for(auto x : s[0]) aux.push_back(x);  
  sort(aux.begin(), aux.end(), [](string a, string b){return a.size()<b.size();}); 
  
  ans += aux[0];
  for(int i = 0; i+1 < aux.size(); i++) {
    multiset<char> s1, s2;
    for(auto x : aux[i]) s1.insert(x);
    for(auto x : aux[i+1]) s2.insert(x);
    for(auto x : s1) s2.erase(s2.find(x));
    ans += *s2.begin();
  }
  reverse(ans.begin(), ans.end());
  cout << "! " << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cout << "? " << 1 << " " << n << endl;
  for(int i = 0; i < (n*(n+1))/2; i++) {
    cin >> a;
    sort(a.begin(), a.end());
    s[0].insert(a);
  }
  if(n > 1){ 
    cout << "? " << 1 << " " << n-1 << endl;
    for(int i = 0; i < (n*(n-1))/2; i++) {
      cin >> a;
      sort(a.begin(), a.end());
      s[1].insert(a);
    }
  }
  mount();
}
