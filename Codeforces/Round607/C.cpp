#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

string sr, sl, c;
int l, sr[3], sl[3], c[3];

void move(){
  int esc = s[l] - '1';
  l++;
  sl[esc]++;
  sr[esc]--;
}

void cut(){
  for(int i = 0; i < 3; i++) {
    c[i] = sr[i];
    s[i] = sl[i];
  }
}

void paste(){
  for(int i = 0; i < 3; i++) s[i] = (s[i] + c[i]) % MOD;
  if(s.size() + c.size() < N) s += c;

}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);

}
