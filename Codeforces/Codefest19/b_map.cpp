#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 5;

int n, a[N];
map<int, int> freq;
vector<int> ax;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int r;
  for(r = n-1; r >= 0; r--){
    if(freq[a[r]] == 1) break;
    freq[a[r]]++;
  }

  int ans = r + 1;
  for(int l = 1; l <= r; l++){
    freq[a[l-1]]++;
    while(r+1 < n and freq[a[l-1]] == 2) r++, freq[a[r]]--;
    if(freq[a[l-1]] == 2) break;
    ans = min(ans, r - l + 1);
  }
  cout << ans << "\n";
}
