#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll t, n, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    //n-k-1 > 0 e k impar ok
    //n-k-1 >= 0 e k par ok
    // n == k e k impar ok
    // n == k+1 e k par ok
    if((k & 1 and n != k+1) or ((k%2 == 0) and n-k-1 >= 0)) cout << "Kilani\n";
    else cout << "Ayoub\n";
  }
}
