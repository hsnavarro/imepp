#include <bits/stdc++.h>
using namespace std;
 
#define int long long

const int LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 400 + 5;
 
int n, r, dp[2][N][N], t[N], tam;
int a, b, w, esc, qu;
vector<int> aux, tempof[N];

struct query{ int i, a, b, k, ans; };

vector<query> q, q1, q2;

bool cmp1(query a, query b){ return a.k < b.k; }
bool cmp2(query a, query b) { return a.i < b.i; }

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> r;
  for(int i = 1; i <= n; i++) {
    cin >> t[i];
    aux.push_back(t[i]);
  }

  sort(aux.begin(), aux.end());
  aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
  tam = aux.size();
  for(int i = 1; i <= n; i++) t[i] = lower_bound(aux.begin(), aux.end(), t[i]) - aux.begin() + 1;
  for(int i = 1; i <= n; i++) tempof[t[i]].push_back(i);
 
  memset(dp, 63, sizeof dp);
 
  for(int i = 1; i <= n; i++){
    for(int k = 0; k < 2; k++) dp[k][i][i] = 0;
  }

  for(int i = 1; i <= r; i++){
    cin >> a >> b >> w;
    for(int k = 0; k < 2; k++) dp[k][a][b] = dp[k][b][a] = w;
  }

  cin >> qu;
  query aux;
  for(int i = 0; i < qu; i++) {
    cin >> aux.a >> aux.b >> aux.k >> esc; 
    aux.i = i, aux.ans = LINF;
    (!esc) ? q1.push_back(aux) : q2.push_back(aux);
  }
  sort(q1.begin(), q1.end(), cmp1);
  sort(q2.begin(), q2.end(), cmp1);

  int k = 1;
  for(auto &x : q1){
    for(; k <= min(x.k, tam); k++)
      for(auto v : tempof[k])
        for(int i = 1; i <= n; i++)
          for(int j = 1; j <= n; j++) dp[0][i][j] = min(dp[0][i][j], dp[0][i][v] + dp[0][v][j]);
    x.ans = dp[0][x.a][x.b];
  }

  k = 1;
  for(auto &x : q2){
    for(; k <= min(x.k, tam); k++)
      for(auto v : tempof[tam - k + 1])
        for(int i = 1; i <= n; i++)
          for(int j = 1; j <= n; j++) dp[1][i][j] = min(dp[1][i][j], dp[1][i][v] + dp[1][v][j]);
    x.ans = dp[1][x.a][x.b];
  }
  
  for(auto x : q1) q.push_back(x);
  for(auto x : q2) q.push_back(x);
  sort(q.begin(), q.end(), cmp2);
  for(auto x : q) cout << (x.ans == LINF ? -1 : x.ans) << "\n";
}
