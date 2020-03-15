#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;

int n, k, pos, vpos;
map<int, int> mp;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= k+1; i++){
    cout << "? ";
    for(int j = 1; j <= k+1; j++) if(i != j) cout << j << " ";
    cout << endl;
    cin >> pos >> vpos;
    mp[vpos]++;
  }

  cout << "! " << mp.rbegin() -> nd << endl;
}
