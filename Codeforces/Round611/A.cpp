#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

int t, h, m;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> h >> m;
    cout << 24*60 - 60*h - m << "\n";
  }

}
