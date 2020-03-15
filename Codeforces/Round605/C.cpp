#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

unsigned long long ans;
int n, k;
char a;
set<char> s;
string s1;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  cin >> s1;
  for(int i = 0; i < k; i++) cin >> a, s.insert(a);

  unsigned long long cnt = 0;

  for(auto x : s1){
    if(!s.count(x)) ans += cnt*(cnt+1), cnt = 0;
    else cnt++;
  }
  ans += cnt*(cnt+1);
  cout << ans/2 << "\n";







}
