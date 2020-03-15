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

int t, x, y;

void ok() { printf("YES\n"); }
void nok() { printf("NO\n"); }

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &x, &y);
    if(x == 1){
      if(y == 1) ok();
      else nok();
    }
    if(x == 2 or x == 3){
      if(y == 1 or y == 3 or y == 2) ok();
      else nok();
    }
    if(x >= 4) ok();
  }
}
