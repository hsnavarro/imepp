#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

vector<ll> del, delcp;
vector<pair<ll, char>> ins, inscp;

char op, c;
ll pos;

void delet(ll p) {
  for(int i = 0; i < ins.size(); i++) {
    if(ins[i].st == p) {
      swap(ins[i], ins.back());
      ins.pop_back();
      for(auto &x : ins) if(x.st > p) x.st--;
      return;
    }
  }
  ll paux = p;
  for(auto x : ins) if(x.st < paux) p--;
  sort(del.begin(), del.end());
  for(auto x : del) if(x <= p) p++;
  del.pb(p);
  for(auto &x : ins) if(x.st > paux) x.st--;
}

void insert(ll p, char c) {
  for(auto &x : ins) if(x.st >= p) x.st++;
  ins.pb({p, c});
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> op and op != 'E') {
    cin >> pos;
    if(op == 'D') delet(pos);
    else cin >> c, insert(pos, c);
  }
  delcp = del, inscp = ins;
  del.clear(), ins.clear();
  while(cin >> op and op != 'E') {
    cin >> pos;
    if(op == 'D') delet(pos);
    else cin >> c, insert(pos, c);
  }

  sort(ins.begin(), ins.end());
  sort(inscp.begin(), inscp.end());
  sort(del.begin(), del.end());
  sort(delcp.begin(), delcp.end());

  cout << !(ins == inscp and del == delcp) << "\n";
}
