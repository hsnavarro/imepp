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

const int N = 2e5 + 5;

ll n, k, a[N], sum[N];

int main(){
  scanf("%lld %lld", &n, &k);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a+n);
  //for(int i = 0; i < n; i++) cout << a[i] << " ";
  //cout << endl;
  for(int i = 0; i < n; i++) sum[i] = a[i] + (i-k >= 0 ? sum[i-k] : 0);

  ll s = 0;
  for(int i = 0; i < n; i++) s += sum[i], printf("%lld ", s);
  printf("\n");
}
