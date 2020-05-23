#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 5;

int lis[N];
string s;

int main() {
  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    lis[i] = 1;
    for(int j = 0; j < i; j++) if(s[j] < s[i]) lis[i] = max(lis[i], lis[j] + 1);
  }
  
  int mx = 0;
  for(int i = 0; i < s.size(); i++) mx = max(mx, lis[i]);
  cout << 26 - mx << "\n";
}
