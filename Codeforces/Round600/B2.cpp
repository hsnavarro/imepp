#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << 
#define _ << ", " << 

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1e5 + 5;

int n, a[N];
set<int> s;
vector<int> pos;
ll sum;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++ ) scanf("%d", &a[i]);
  pos.pb(-1);
  for(int i = 0; i < n; i++){
    sum += a[i];
    if(!sum) pos.pb(i);
  }

  if(sum) return printf("-1\n"), 0;
  
  for(int i = 0, p = 1; i < n; i++){
    if(a[i] < 0) {
      if(!s.count(abs(a[i]))) return printf("-1\n"), 0;
    } else {
      if(s.count(a[i])) return printf("-1\n"), 0;
    }
    s.insert(abs(a[i]));
    if(i == pos[p]) s.clear(), p++;
  }

  printf("%d\n", pos.size()-1);
  for(int i = 1; i < pos.size(); i++) printf("%d ", pos[i]-pos[i-1]);
  printf("\n");
}
