#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define db(x) cerr << #x << " == " << 
#define _ << ", " << 

const int N = 100 + 5;

int p, q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> p >> q;
  int pPar = (p%2 == 0);
  int qPar = (q%2 == 0);

  if(pPar) cout << 0 << "\n";
  else {
    if(!qPar) cout << 1 << "\n";
    else {
      if(p > q) cout << 0 << "\n";
      else cout << 2 << "\n";
    }
  }
}
