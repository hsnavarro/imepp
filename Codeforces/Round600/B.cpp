#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << 
#define _ << ", " << 

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1e6 + 5;

ll n, a[N], enter[N], ctrl[N], sum, l, cnt;
vector<ll> evs;

// formas de dar ruim
// ctrl[emp] < 0 em qqer momento
// dia acaba e sum != 0

int main(){
  scanf("%lld", &n);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

  for(int i = 0; i < n; i++){
    if(ctrl[abs(a[i])] < 0) {
      //cout << "caso 1" << endl;
      return printf("-1\n"), 0;
    }
    if(a[i] < 0) { sum += a[i]; continue; }
    if(enter[a[i]] == cnt+1){
      if(sum != 0) {
        //cout << "caso 2" << endl;
        return printf("-1\n"), 0;
      }
      cnt++, evs.push_back(i-1 - l + 1), l = i;
    }
    enter[a[i]] = cnt+1, sum += a[i];
  }

  if(sum != 0) return printf("-1\n"), 0;
    evs.push_back(n-1 - l + 1);

  printf("%d\n", evs.size());
  for(auto x : evs) printf("%lld ", x);
  printf("\n");

}
