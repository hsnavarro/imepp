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
const int N = 1e5 + 5;

int n;
string s;

void go(string s){
  string a, b, c;
  for(int i = s.size() - 1; i >= 0; i--){
    if(a.size() < 2) a += s[i];
    if(b.size() < 4) b += s[i];
    if(c.size() < 5) c += s[i];
  }
  if(a == "op") cout << "FILIPINO\n";
  if(b == "used" or b == "usam") cout << "JAPANESE\n";
  if(c == "adinm") cout << "KOREAN\n";
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--){
    cin >> s;
    go(s);
  }

}
