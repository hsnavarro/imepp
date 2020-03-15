#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;

bool check(int n){
  string s = to_string(n);
  int sum = 0;
  for(auto x : s) sum += (x - '0');
  return sum % 4 == 0;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(!check(n)) n++;
  cout << n << "\n";
}
