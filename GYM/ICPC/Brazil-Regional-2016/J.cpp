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

bool isprime(int x){
  for(int i=2; i*i<=x; i++){
    if(x%i == 0) return false;
  }
  return true;
}

int main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  while(scanf("%d", &n) != EOF){
    for(int i=0; i<2000; i++){
      if(isprime(n)){ printf("%d\n", n); break;}
      n--;
    }
  }
}
