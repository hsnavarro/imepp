#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second
#define pb push_back

const int N = 1e5 + 5;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int t;
int n, x, a, b;

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d%d%d%d", &n, &x, &a, &b);
    if(a > b) swap(a, b);
    printf("%d\n", min(n-1, b-a+x));
  }

}
