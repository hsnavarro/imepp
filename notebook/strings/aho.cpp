// Aho-Corasick - <O(sum(m)), O(n + #matches)>

// number of nodes
const int N = 1e5 + 5;
// number of strings 
const int S = 2e3 + 5;

int nxt[N][26], ch[N], p[N], f[N], szt = 1, cnt[N];
bitset<S> elem[N];

void add(string &pt, int x) {
  int u = 1;
  for(auto c : pt) {
    int j = c - 'a';
    if(!nxt[u][j]) {
      szt++;
      ch[szt] = j;
      p[szt] = u;
      nxt[u][j] = szt;
    }
    u = nxt[u][j];
  }
  cnt[u]++;
  elem[u].set(x);
}

void build() {
  queue<int> q;
  for(int i = 0; i < 26; i++) {
    nxt[0][i] = 1;
    if(nxt[1][i]) q.push(nxt[1][i]);
  }
  while(q.size()) {
    int v = q.front(); q.pop();
    int u = f[p[v]];
    while(u and !nxt[u][ch[v]]) u = f[u];
    f[v] = nxt[u][ch[v]];
    cnt[v] += cnt[f[v]];
    elem[v] |= elem[f[v]];
    for(int i = 0; i < 26; i++) {
      if(nxt[v][i]) q.push(nxt[v][i]);
      /* Pre-Computation of next states
      else {
        int ax = f[v];
        while(ax and !nxt[ax][i]) ax = f[ax];
        nxt[v][i] = nxt[ax][i];
      }
      */
    }
  }
}

int match(string &s) {
  int s = 0, u = 1;
  bitset<S> ans;
  for(auto c : s) {
    int j = c - 'a';
    while(u and !nxt[u][j]) u = f[u];
    u = nxt[u][j];
    s += cnt[u];
    ans |= elem[u];
  }
  return s;
} 
