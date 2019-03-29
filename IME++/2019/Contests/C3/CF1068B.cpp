#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll b;
int cnt;

int main(){
  scanf("%lld", &b);
  for(ll i = 1; i*i <= b; i++){
    if(b % i == 0){
      if(i * i != b) cnt += 2;
      else cnt++;
    }
  }
  printf("%d\n", cnt);
}
