#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  v.resize(n);
  ll sum = 0;
  for(int i = 0; i < n; i++) cin >> v[i], sum += v[i];
  ll aux = sum;
  sum /= n;
  ll rest = aux - sum*n;
  //cout << "sum, rest " << sum << " " << rest << endl;
  sort(v.begin(), v.end());
  ll ans = 0;
  vector<int> id(n);
  for(int i = n-1; i >= 0; i--) {
    id[i] = sum + (rest > 0);
    rest--;
  }

  //for(int i = 0; i < n; i++) cout << id[i] << " ";
  //cout << endl;

  int r = n-1;
  for(int i = 0; i < n; i++) {
    ans += id[i] - v[i];
    int val = id[i] - v[i];
    while(val > 0) {
      //cout << "i, val " << i << " " << val << endl;
      //getchar();
      int x = min(val, v[r] - id[r]);
      v[r] -= x;
      val -= x;
      if(v[r] == id[r]) r--;
    }

  }
  cout << ans << "\n";
}
