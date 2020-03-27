#include <bits/stdc++.h>
using namespace std;

#define sort(x) sort(x.begin(), x.end(), greater<char>())

string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int cond = 1;
  while(cond) {
    cond = 0;
    sort(s);
    string aux;
    for(int i = 0; i < s.size(); i++) {
      if(i+1 < s.size() and s[i] != 'z' and s[i] == s[i+1]) cond = 1, aux += (char) s[i]+1, i++;
      else aux += (char) s[i];
    }
    s = aux;
  }
  cout << s << "\n";
}
