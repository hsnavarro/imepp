#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

int n;
string a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> a >> b;
  int cnt1 = 0, cnt2 = 0;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) cnt1++;
    else cnt2++;
  }
  if(cnt2 >= n) cout << n + cnt1 << "\n";
  else cout << cnt1 - n + 2*cnt2 << "\n";
}
