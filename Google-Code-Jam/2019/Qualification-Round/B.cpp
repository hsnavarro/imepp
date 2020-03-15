#include <bits/stdc++.h>
using namespace std;

char opos(char s){
  if(s == 'E') return 'S';
  return 'E';
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t, n, cnt = 0;;
  string s, ans;
  cin >> t;
  while(t-- and ++cnt){
    cin >> n >> s;
    cout << "Case #" << cnt << ": ";
    for(auto x : s) cout << opos(x);
    cout << endl;
  }
}
