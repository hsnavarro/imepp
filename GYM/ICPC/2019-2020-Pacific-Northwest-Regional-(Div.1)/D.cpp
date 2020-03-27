#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

ll a, b;
int cnt;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  while(a > b) {
    if(a & 1) a++, cnt++;
    a/= 2, cnt++;
  }
  cout << (b-a) + cnt << "\n";
}
