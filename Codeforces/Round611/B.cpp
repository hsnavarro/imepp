#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

int t;
ll n, k;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> k;
    cout << min(n, n/k*k + k/2) << "\n";
  }
}
