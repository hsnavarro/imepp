#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 5;

int t, ok[N];
string s, a = "one", b = "two", aux;
vector<int> ans;

void process(string s){
  for(int i = 0; i < s.size(); i++){
    if(i - 1 >= 0 and i + 3 < s.size()) {
      if(s[i-1] == 't' and s[i] == 'w' and s[i+1] == 'o' and s[i+2] == 'n' and s[i+3] == 'e') { ans.pb(i+1); i += 2; continue; }
    }

    if(i - 1 >= 0 and i + 1 < s.size()) {
      if(s[i-1] == 't' and s[i] == 'w' and s[i+1] == 'o') ans.pb(i);
    }

    if(i - 1 >= 0 and i + 1 < s.size()) {
      if(s[i-1] == 'o' and s[i] == 'n' and s[i+1] == 'e') ans.pb(i);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    ans.clear();
    cin >> s;
    process(s);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x+1 << " ";
    cout << "\n";

  }
}
