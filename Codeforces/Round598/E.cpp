#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

// dp[i] melhor resposta até i considerando que vou finalizar um time em i
ll n, a[N], idx[N];
ll dp[N];
priority_queue<ll> pq;
vector<ll> pos;

void recover(int x){
  int nxt = x-3;
  while(nxt >= 0 and dp[x] != dp[nxt] + a[idx[x]] - a[idx[(x+1)%n]]) nxt--;
  if(nxt < 0) return;
  pos.push_back(nxt);
  recover(nxt);
}

int main(){
  scanf("%lld", &n);
  for(int i = 0; i < n; i++) idx[i] = i, scanf("%lld", &a[i]);
  memset(dp, 63, sizeof dp);
  sort(idx, idx+n, [] (ll i, ll j) { return a[i] < a[j]; });
  for(int i = 0; i < n; i++){
    if(i >= 2) dp[i] = a[idx[i]] - a[idx[(i+1)%n]];
    if(i >= 5) {
      pq.push(-dp[i-3]);
      dp[i] = min(dp[i], dp[i] - pq.top());
    }
  } 

  recover(n-1);
  printf("%lld %d\n", dp[n-1], pos.size()+1);
  for(int cnt = pos.size()-1, i = 0; i < n; i++){
    a[idx[i]] = cnt+2;
    if(cnt >= 0 and i == pos[cnt]) cnt--;
  }

  for(int i = 0; i < n; i++) printf("%lld ", a[i]);
  printf("\n");
  
}
