#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;

int n, ok, a, x;
char esc;
set<int> s;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> esc >> a;
    if(esc == '+') ok ? s.insert((a+x)%MOD) : s.insert(a), ok = 0;
    else {
      auto it = s.lower_bound(a);
      ok = 1, it == s.end() ? x = -1 : x = *it;
      cout << x << endl;
    }
  }
}
