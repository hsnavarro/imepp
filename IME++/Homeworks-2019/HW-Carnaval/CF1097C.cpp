#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, ans, cnt,  e, d;
string s;
pair<int, int> p[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    e = d = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
      if(e >= 0) s[i] == '(' ? e++ : e--;
      if(d >= 0) s[s.size() - 1 - i] == ')' ? d++ : d--;
    }

    if(e < 0 and d < 0) continue;
    if(e == 0 and d == 0) ans++;
    else{
      if(e > 0) p[e].first++;
      if(d > 0) p[d].second++;
      }
    }

    for(auto x : p)  cnt += min(x.first, x.second);
    cout << cnt + ans/2 << endl;
}
