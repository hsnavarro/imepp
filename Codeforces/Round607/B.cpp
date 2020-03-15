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

int t;
string s, c;

void go(){
  int mn[5005];
  int a = INF, idx;
  for(int i = s.size() - 1; i >= 0; i--){
    if(s[i] < a) a = s[i], idx = i;
    mn[i] = idx;
  }

  for(int i = 0; i < s.size(); i++){
    if(s[i] > s[mn[i]]) { swap(s[i], s[mn[i]]); break; }
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> s >> c;
    go();
    //db(s);
    if(s < c) cout << s << "\n";
    else cout << "---\n";
  }
}
