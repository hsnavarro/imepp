#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m, upper;
string ans, inp, cons;
vector<string> ins;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> inp, ans += inp, ans += ' ';
  ans.pop_back();
  cin >> m;
  ins.resize(m);
  for(int i = 0; i < m; i++) cin >> ins[i];

  int cond = 1;
  for(auto x : ins) {
    if(x == "CapsLock") upper = 1 - upper;
    else if(x == "Space") cons += ' ';
    else if(x == "Backspace") {
      if(cons.size()) cons.pop_back();
    }
    else {
      if(upper) cons += x[0] - 'a' + 'A';
      else cons += x[0];
    }
  }

  cout << ((cons == ans) ? "Correct\n" : "Incorrect\n");
}
