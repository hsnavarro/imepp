#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool check(string s){
  sort(s.begin(), s.end());
  for(int i = 0; i + 1 < s.size(); i++) if(s[i+1] - s[i] != 1) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> s;
    cout << (check(s) ? "Yes" : "No") << endl;
  }
}
