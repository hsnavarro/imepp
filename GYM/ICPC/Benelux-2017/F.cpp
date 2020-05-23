#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define db(x) cerr << #x << " == " << x << endl 
#define _ << ", " << 

int n, sa, sb;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  for(int i = 0; i < n; i++) ((i & 1) ? sb : sa) += a[i]; 
  cout << sa << " " << sb << "\n";
}
