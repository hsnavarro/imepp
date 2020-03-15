#include <bits/stdc++.h>
using namespace std;

int x, n, ans[9000 + 5];
set<int> a;

bool isPerf(int n){
  int sum = 0;
  for(int i = 2; i*i <= n; i++) {
    if(n % i == 0){
      sum += i;
      if(i*i != n) sum += n/i;
    }
  }
  sum += (n != 1);
  return (sum == n);
}

int main(){
  scanf("%d", &n);
  int mx = -1;
  for(int i = 0; i <= 9000; i++) {
    if(isPerf(i)) mx = i;
    ans[i] = mx;
  }

  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    x = min(x, 9000);
    printf("%d\n", ans[x]);
  }


}
