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

const int N = 1e5 + 5;

int t, n, aux, eq, a[N], b[N], cnt, cond;

int main(){
  scanf("%d", &t);
  while(t--){
    cnt = 0, cond = 0, eq = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    for(int i = 0; i < n; i++) if(b[i] - a[i] < 0) cond = 1;
    for(int i = 0; i < n; i++) if(a[i] != b[i]) eq = 0;
    if(eq) {
      printf("YES\n");
      continue;
    }
    if(cond){
      printf("NO\n");
      continue;
    }

    int l = 0, r = 0;
    for(int i = 0; i < n; i++) if(a[i] != b[i]) { l = i, aux = b[i] - a[i]; break; }
    r = l;
    while(r < n and a[r] != b[r]) r++;
    for(int i = l; i < r; i++) a[i] += aux;
   
    eq = 1;
    for(int i = 0; i < n; i++) if(a[i] != b[i]) eq = 0;
    printf("%s\n", (!eq) ? "NO" : "YES");
  }


}
