#include <bits/stdc++.h>
using namespace std;

int n, q, esc;
vector<int> v;

int main(){
  scanf("%d%d", &n, &q);
  v.resize(n);
  for(int i = 0; i < n; i++) scanf("%d", &v[i]);
  while(q--){
    scanf("%d", &esc);
    int up = lower_bound(v.begin(), v.end(), esc) - v.begin();
    printf("%d\n", up < n and v[up] == esc ? up : -1);
  }
}
