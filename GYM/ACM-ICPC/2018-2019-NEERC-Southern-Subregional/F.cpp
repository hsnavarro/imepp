#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

const int N = 2e5+5;

int n, f[30], ans[N], idx;
pair<int, int> t[N];

int unluck(int x){
  string aux = to_string(x);
  int sum = 0;
  for(int i = 0; i < aux.size(); i++){
    if(i > 2) sum += aux[aux.size()-1-i] - '0';
    else sum -= aux[aux.size()-1-i] - '0';
  }
  return abs(sum);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t[i].st;
    t[i].nd = i;
  }
  sort(t, t+n);
  for(int i = 0; i < n; i++){
    while(idx < t[i].st) f[unluck(idx)]++, idx++;
    for(int j = 0; j < unluck(t[i].st); j++) ans[t[i].nd] += f[j];
  }

  for(int i = 0; i < n; i++) cout << ans[i] << endl;
}
