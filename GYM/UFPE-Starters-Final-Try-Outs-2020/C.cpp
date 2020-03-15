#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

const int N = 1e6 + 5;

struct query{
  int op, idx;
  string s;
}; 

bool cmp(pair<string, int> x, pair<string, int> y){
  if(x.st == y.st) return x.nd < y.nd;
  if(x.st.size() == y.st.size()) return x.st < y.st;
  return x.st.size() < y.st.size();
}

int cnt = 1, q, word, op, idx, ord[N], trie[N][26];
set<pair<int, int>> st[N];
string s;
map<string, int> id;
vector<query> perg;
vector<pair<string, int>> words;

void op1(string s){
  int idx = id[s], ordn = ord[idx], node = 1;
  st[node].insert({ordn, idx});
  for(auto x : s){
    if(!trie[node][x - 'a']) trie[node][x - 'a'] = ++cnt;
    node = trie[node][x - 'a'];
    st[node].insert({ordn, idx});
  }
}

void op2(int idx){
  int ordn = ord[idx], node = 1;
  string s = words[ordn].st;
  st[node].erase({ordn, idx});
  for(auto x : s){
    node = trie[node][x - 'a'];
    st[node].erase({ordn, idx});
  }
}

int op3(string s){
  int node = 1;
  for(auto x : s) node = trie[node][x - 'a'];
  if(!st[node].size()) return cout << -1 << "\n", 0;
  pair<int, int> a = *(st[node].begin());
  return cout << a.nd << "\n", 1;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q-- and ++word){
    s.clear();
    cin >> op;
    if(op == 1 or op == 3) cin >> s;
    else cin >> idx;
    if(op == 1) id[s] = word, words.push_back({s, word});
    perg.pb({op, idx, s});
  }
  sort(words.begin(), words.end(), cmp);
  for(int i = 0; i < words.size(); i++) ord[words[i].nd] = i;
  
  for(auto q : perg){
    if(q.op == 1) op1(q.s);
    if(q.op == 2) op2(q.idx);
    if(q.op == 3) op3(q.s);
  }
}
