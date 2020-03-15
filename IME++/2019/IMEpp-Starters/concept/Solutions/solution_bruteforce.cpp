#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, q, esc, a, b, notes[N];

int calc(int l, int r){
  int sum = 0, mx = -INF, mn = INF;
  for(int i = l; i <= r; i++){
    sum += notes[i];
    mx = max(mx, notes[i]);
    mn = min(mn, notes[i]);
  }
  return sum - mx - mn;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> notes[i];
  while(q--){
    cin >> esc >> a >> b;
    if(esc == 1) cout << calc(a, b) << endl;
    else notes[a] = b;
  }
}
