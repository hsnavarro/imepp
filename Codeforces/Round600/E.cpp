#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << 
#define _ << ", " << 

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1e5 + 5;

int n, m, x, sc;
vector<pair<int, int>> rng;
int dp[N], cov[N];

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &x, &sc);
    rng.pb({max(1, x-sc), min(m, x+sc)});
    for(int j = rng.back().st; j <= rng.back().nd; j++) cov[j] = 1;
  }
  for(int i = 1; i <= m; i++){
    dp[i] = i;
    if(cov[i]) dp[i] = min(dp[i-1], dp[i]);
    else for(auto x : rng) if(x.nd <= i) dp[i] = min(dp[i], i-x.nd + dp[max(x.st-i+x.nd-1, 0)]);
  }
  printf("%d\n", dp[m]);
}
