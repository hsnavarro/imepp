#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int l, r, res, q, s1[N], s2[N], a1, a2;
string s;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> s;
  for(int i = 1; i < s.size(); i++){
    if(s[i] == s[i-1])  s[i] == '.' ? a1++ : a2++;
    s1[i] += a1;
    s2[i] += a2;
  }
  
  cin >> q;
  while(q--){
    cin >> l >> r;
    res = (s1[r-1] - s1[l-1]) + (s2[r-1] - s2[l-1]);
    cout << res << "\n";
  }
}
