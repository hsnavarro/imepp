#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const ld PI = acos(-1.0);

#define db(x) cerr << #x << " == " << 
#define _ << ", " << 

ld M, N, R;
ld ax, ay, bx, by;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> M >> N >> R;
  cin >> ax >> ay >> bx >> by;
  
  ld mn = 1e18;
  for(int i = 0; i <= min(ay, by); i++) mn = min(mn, abs(ax-bx) * (PI/M) * (R/N) * ld(i) + abs(ay - ld(i)) * (R/N) + abs(by - ld(i)) * (R/N));

  cout << fixed << setprecision(14) << mn << "\n";
}
