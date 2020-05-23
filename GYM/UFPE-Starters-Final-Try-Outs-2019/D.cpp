#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int trie[N][10], isEnd[N], triend = 1;
int u = 1;
int n, q;
string s;

int number(char x) {
  if(x >= '0' and x <= '9') return x - '0';
  int a = x - 'a';
  a = a/3 + 2;
  if(a <= 6) return a;
  if(x >= 'p' and x <= 's') return 7;
  if(x >= 't' and x <= 'v') return 8;
  return 9;
}

void add(string &a) {
  int u = 1;
  for(auto x : a) {
    int num = number(x);
    if(!trie[u][num]) trie[u][num] = ++triend;
    u = trie[u][num];
    isEnd[u]++;
  }
}

int query(string &s) {
  int u = 1;
  for(auto x : s) u = trie[u][number(x)];
  return isEnd[u];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  while(n--) {
    cin >> s;
    add(s);
  }
  while(q--) {
   cin >> s;
   cout << query(s) << "\n"; 
  }
}

