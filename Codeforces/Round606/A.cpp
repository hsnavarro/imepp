#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int t, ans, n;

void build(int x){
  string aux;
  char a = '0' + x;
  aux += a;
  while(aux.size() <= 9 and stoi(aux) <= n) ans++, aux += a;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    ans = 0;
    for(int i = 1; i <= 9; i++) build(i);
    cout << ans << "\n";
  }
}
