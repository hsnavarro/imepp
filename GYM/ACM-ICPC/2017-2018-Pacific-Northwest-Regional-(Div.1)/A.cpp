#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int cond = 1;
  for(int i = 0; i+1 < s.size(); i++) {
    if(s[i] == s[i+1]) cond = 0;
  }
  cout << (cond ? "Odd.\n" : "Or not.\n");
}
