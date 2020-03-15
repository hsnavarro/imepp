#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  string ans;
  int cond = 1;
  while(cond) {
    cond = 0;
    for(int i = 0; i < s.size(); i++) {
      if(i+1 < s.size() and s[i] != 'z' and s[i] == s[i+1]) {
        ans += char(s[i]+1), i++, cond = 1;
      } else ans += s[i];
    } 
    s = ans;
    ans.clear();
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
  }
  cout << s << "\n";
}
