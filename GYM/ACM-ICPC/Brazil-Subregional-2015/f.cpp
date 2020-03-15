#include <bits/stdc++.h>
using namespace std;

int n, fat[11], cnt;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  fat[0] = 1;
  for(int i = 1; i < 11; i++) fat[i] = i*fat[i-1];
  cin >> n;
  for(int i = 10; i >= 0; i--) while(fat[i] <= n) n -= fat[i], cnt++;
  cout << cnt << "\n";
}
