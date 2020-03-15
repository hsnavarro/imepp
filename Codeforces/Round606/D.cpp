#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int t, n, zz, zo, oz, oo;
string in;
set<string> st;
vector<pair<string, int>> s[2];
vector<int> idx[2];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    zz = zo = oz = oo = 0;
    st.clear();
    for(int k = 0; k < 2; k++) s[k].clear(), idx[k].clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> in; 
      if(in[0] == '0'){
        if(in.back() == '0') zz++;
        if(in.back() == '1') zo++, s[0].pb({in, i});
      } else {
        if(in.back() == '1') oo++;
        if(in.back() == '0') oz++, s[1].pb({in, i});
      }
      st.insert(in);
    }
    for(int j = 0; j < 2; j++){
      for(auto x : s[j]) {
        string aux = x.st;
        reverse(aux.begin(), aux.end());
        if(!st.count(aux)) idx[j].pb(x.nd);
      }
    }

    int cond = 1, x = abs(zo - oz)/2;
    if(oo and zz and !zo and !oz) cond = 0;
    if(x > idx[zo <= oz].size()) cond = 0;
    
    if(!cond) cout << -1 << "\n";
    else {
      cout << x << "\n";
      for(int i = 0; i < x; i++) cout << idx[zo <= oz][i] << " ";
      cout << "\n";
    }
  }
}
