#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " << 

const int N = 30;

int m;
string s;
int player, reply;

// for letter i
// va(i) -> i belongs to 1
// vb(i) -> i belongs to 2

int vis[4*N], ord[4*N], ordn, cnt, cmp[4*N];
vector<int> adj[4*N], adjt[4*N];
vector<int> adjb[4*N], adjtb[4*N];

int va(int x) { return 2*x; }
int nva(int x) { return 2*x+1; }

int vb(int x) { return 2*x + 2*N; }
int nvb(int x) { return 2*x + 1 + 2*N; }

void clear() {
  for(int i = 0; i < 4*N; i++) {
    vis[i] = ord[i] = cmp[i] = 0;
    adj[i] = adjb[i];
    adjt[i] = adjtb[i];
  }

  ordn = 0;
  cnt = 0;
}

void add(int a, int b) {
  adjb[a].pb(b);
  adjb[b^1].pb(a^1);
  adjtb[b].pb(a);
  adjtb[a^1].pb(b^1);
}

void add2(int a, int b) {
  adj[a].pb(b);
  adj[b^1].pb(a^1);
  adjt[b].pb(a);
  adjt[a^1].pb(b^1);
}

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v]) dfs(v);
  ord[ordn++] = x;
}

void dfst(int x){
  cmp[x] = cnt, vis[x] = 0;
  for(auto v : adjt[x]) if(vis[v]) dfst(v);
}

bool run2sat(){
  for(int i = 1; i <= 26; i++) {
    if(!vis[va(i)]) dfs(va(i));
    if(!vis[vb(i)]) dfs(vb(i));

    if(!vis[nva(i)]) dfs(nva(i));
    if(!vis[nvb(i)]) dfs(nvb(i));
  }
  for(int i = ordn-1; i >= 0; i--) 
    if(vis[ord[i]]) cnt++, dfst(ord[i]);
  for(int i = 1; i <= 26; i++){
    if(cmp[va(i)] == cmp[nva(i)]) return false;
    if(cmp[vb(i)] == cmp[nvb(i)]) return false;
  }
  return true;
}

// xor: a -> !b ^ !a -> b
// false: a -> !a
// true: !a -> a

int generate() {
  int cnt = 0;
  for(int i = 1; i <= 26; i++) 
    for(int j = i + 1; j <= 26; j++) 
      for(int k = j + 1; k <= 26; k++) {
          clear();

          add2(va(i), nva(i));
          add2(vb(i), nvb(i));
          
          add2(va(j), nva(j));
          add2(vb(j), nvb(j));
          
          add2(va(k), nva(k));
          add2(vb(k), nvb(k));

          for(int z = 1; z <= 26; z++)
            if(z != i and z != j and z != k) add2(va(z), nvb(z)), add2(nva(z), vb(z));


          if(run2sat()) cnt++;
        }
  
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> m;

  for(int i = 1; i <= 26; i++) add(va(i), nvb(i));

  while(m--) {
    cin >> s >> player >> reply;
    
    int x = s[0] - 'A' + 1;
    int y = s[1] - 'A' + 1;

    if(reply == 2) {
      if(player == 1) add(nva(x), va(x)), add(nva(y), va(y));
      else add(nvb(x), vb(x)), add(nvb(y), vb(y)); 
    } else if(reply == 1) {
      if(player == 1) add(va(x), nva(y)), add(nva(x), va(y));
      else add(vb(x), nvb(y)), add(nvb(x), vb(y));
    } else {
      if(player == 1) add(va(x), nva(x)), add(va(y), nva(y));
      else add(vb(x), nvb(x)), add(vb(y), nvb(y));
    }
  }

  cout << generate() << "\n";
}
