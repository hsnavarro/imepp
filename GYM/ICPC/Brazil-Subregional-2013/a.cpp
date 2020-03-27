#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int a, b, c;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> a >> b >> c){
    if(a != b and a != c) cout << "A\n";
    else if(b != a and b != c) cout << "B\n";
    else if(c != a and c != b) cout << "C\n";
    else cout << "*\n";
  }
} 
