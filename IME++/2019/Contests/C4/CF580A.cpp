#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, a[N], mx = -1, cnt = 1;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 1; i < n; i++){
    if(a[i] >= a[i-1]) cnt++;
    else mx = max(mx, cnt), cnt = 1;
  }
  cout << max(mx, cnt) << endl;
}
