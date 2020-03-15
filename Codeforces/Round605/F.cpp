#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e2 + 5;

struct state { int i, j, bal; };

string s, t, ans;
int dp[N][N][N];
pair<char, state> par[N][N][N];

// dp[pos in s][pos in t][balance] = min size of ans

void bfs(){
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      for(int k = 0; k < N; k++) par[i][j][k] = {'#', {-1, -1, -1}};
  memset(dp, INF, sizeof dp);
  dp[0][0][0] = 0;
  queue<state> q;
  q.push({0, 0, 0});
  while(q.size()){
    state aux = q.front();
    q.pop();
    int i = aux.i;
    int j = aux.j;
    int bal = aux.bal;
    if(i == s.size() and j == t.size() and !bal) return;
    // place '('
    bal++;
    if(i < s.size() and s[i] == '(') i++;
    if(j < t.size() and t[j] == '(') j++;
    if(bal <= 200 and i <= s.size() and j <= t.size() and dp[i][j][bal] == INF) {
      dp[i][j][bal] = dp[aux.i][aux.j][aux.bal] + 1;
      q.push({i, j, bal}), par[i][j][bal] = {'(', {aux.i, aux.j, aux.bal}};
    }

    // place ')'
    i = aux.i, j = aux.j, bal = aux.bal;
    bal--;
    if(i < s.size() and s[i] == ')') i++;
    if(j < t.size() and t[j] == ')') j++;
    if(bal >= 0 and i <= s.size() and j <= t.size() and dp[i][j][bal] == INF) {
      dp[i][j][bal] = dp[aux.i][aux.j][aux.bal] + 1;
      q.push({i, j, bal}), par[i][j][bal] = {')', {aux.i, aux.j, aux.bal}};
    }
  }
}

void rec(int i, int j, int bal){
  if(par[i][j][bal].st == '#') return;
  ans += par[i][j][bal].st;
  state st = par[i][j][bal].nd;
 rec(st.i, st.j, st.bal);
}


int main(){
  cin >> s >> t;
  bfs();
  rec(s.size(), t.size(), 0);
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
