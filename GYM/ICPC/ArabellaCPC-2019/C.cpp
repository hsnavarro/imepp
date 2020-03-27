#include <bits/stdc++.h>
using namespace std;

int n, m, upper;
string inp, ans, cons;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> inp, ans += inp + ' ';
  ans.pop_back();
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> inp;
    if(inp == "CapsLock") upper ^= 1;
    else if(inp == "Space") cons += ' ';
    else if(inp == "Backspace") { if(cons.size()) cons.pop_back(); }
    else {
      if(upper) cons += inp[0] - 'a' + 'A';
      else cons += inp[0];
    }
  }
  cout << (ans == cons ? "Correct\n" : "Incorrect\n");
}


