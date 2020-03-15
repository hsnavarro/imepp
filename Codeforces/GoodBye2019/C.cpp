#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f;

int t, n, a;
ll x, sum;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    sum = x = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a, x = x^a, sum += a;
    cout << 2 << "\n";
    cout << x << " " << sum+x << "\n";
  }
}
