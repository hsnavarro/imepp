#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef long double ld;

const int N = 100 + 5;

int n;
ld x, v;
ld lf[N], rt[N], vl[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> x >> v;
  for(int i = 0; i < n; i++) {
    cin >> lf[i] >> rt[i] >> vl[i];
  }

  ld vy = 0;
  for(int i = 0; i < n; i++) vy += vl[i]*(rt[i] - lf[i]);
  vy *= -1.0;
  vy = vy/x;

  if(v*v - vy*vy < 0) {
    cout << "Too hard\n";
    return 0;
  }
  ld vx = sqrt(v*v - vy*vy);
  ld t = x/vx;
  if(t > 2*x/v) cout << "Too hard\n";
  else cout << fixed << setprecision(3) << t << "\n";
}
