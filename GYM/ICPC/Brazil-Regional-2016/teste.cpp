#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
long double v[100] , n;
int main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  v[0] = 0.0;
  v[1] = 1.0;
  for(int i = 2; i<=(int)n; i++){
    v[i] = (1.0-(i-2.0)/(n-1.0))*(1.0/(n-1.0));
    cout << i << " " << v[i] << "\n";
  }
}

