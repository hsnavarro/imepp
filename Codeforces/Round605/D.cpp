#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 5;

int n, a[N], dp[N], dp2[N], cnt;
int ans = 0;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i], dp[i] = 1, dp2[i] = 1;

  for(int i = 1; i < n; i++) {
    if(a[i] > a[i-1]) cnt++;
    else cnt = 0;
    dp[i] += cnt;
    ans = max(ans, dp[i]);
  }

  cnt = 0;
  for(int i = n-2; i >= 0; i--) {
    if(a[i+1] > a[i]) cnt++;
    else cnt = 0;
    dp2[i] += cnt;
    ans = max(ans, dp2[i]);
  
  }

  for(int i = 1; i < n-1; i++){
    if(a[i-1] < a[i+1]) ans = max(ans, dp[i-1] + dp2[i+1]);
  }

  cout << ans << "\n";





}
