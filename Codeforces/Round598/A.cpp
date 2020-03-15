#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

ll q, a, b, n, s;

int main(){
  scanf("%lld", &q);
  while(q--){
    scanf("%lld %lld %lld %lld", &a, &b, &n, &s);

    ll x = min(a, s/n);
    s -= x*n;

    if(s <= b) printf("YES\n");
    else printf("NO\n");
  }
}
