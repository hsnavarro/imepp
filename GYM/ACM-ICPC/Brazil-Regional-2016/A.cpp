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

int main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  int a, b, c, d;
  while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF){
    int ans = abs((a+d) - (b+c));
    printf("%d\n", ans);
  }
}
