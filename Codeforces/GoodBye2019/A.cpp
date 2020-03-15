#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;

int t, n, k, k1, k2, a;
vector<int> p1, p2;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> k1 >> k2;
    p1.resize(k1), p2.resize(k2);
    for(int i = 0; i < k1; i++) cin >> p1[i];
    for(int i = 0; i < k2; i++) cin >> p2[i];

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    cout << (p1.back() > p2.back() ? "YES\n" : "NO\n");
  }
}
