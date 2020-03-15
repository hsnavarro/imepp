#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int c, p, s;
ll pont;
string a, b, cc;
map<string, ll> score, pts;
vector<string> in;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> c >> p >> s;
  for(int i = 0; i < c; i++) cin >> a, in.push_back(a);
  for(int i = 0; i < p; i++) cin >> a >> pont, pts[a] = pont;
  for(int i = 0; i < s; i++){
    cin >> a >> b >> cc;
    if(cc == "AC") score[a] += pts[b];
  }

  for(auto x : in){
    cout << x << " " << score[x] << "\n";
  }

}
