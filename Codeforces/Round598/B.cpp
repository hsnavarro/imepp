#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int q, n, a[105];
set<int> p;

int main(){
  scanf("%d", &q);
  while(q--){
    p.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      if(i) p.insert(i);
      scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; i++){
      for(int j = 0; j < n; j++){
        if(a[j] == i){
          int pos = j;
          while(pos > 0 and i < a[pos-1] and p.count(pos)) p.erase(pos), swap(a[pos], a[pos-1]), pos--;
        }
      }
    }

    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

  }
  

}
