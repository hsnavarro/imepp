#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int N = 2e5 + 5;

ll n, m, k, s, a, b, cnt1, cnt2;
pll type1[N], type2[N], mna[N], mnb[N];
vector<pll> ans;

bool check(int x) {
  int l1 = 0, l2 = 0;
  ll money = s;
  ans.clear();
  for(int i = 0; i < k; i++) {
    ll op1 = INF, op2 = INF, op1_d, op2_d;
    if(l1 < cnt1 and x) op1 = type1[l1].st * mna[x].st;
    if(l2 < cnt2 and x) op2 = type2[l2].st * mnb[x].st;
    if(op1 < op2) {
      if(money < op1) return false;
      money -= op1;
      ans.push_back({type1[l1].nd, mna[x].nd});
      l1++;
    } else {
      if(money < op2) return false;
      money -= op2;
      ans.push_back({type2[l2].nd, mnb[x].nd});
      l2++;
    }
  }
  return true;
}

ll bin(ll l = 0, ll r = n) {
  ll mid;
  while(l != r) {
    mid = (l+r)/2;
    if(!check(mid)) l = mid+1;
    else r = mid;
  }
  if(!check(l)) return -1;
  return l;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k >> s;
  ll mn = INF, idx;
  for(int i = 1; i <= n; i++) {
    cin >> a;
    if(a < mn) mn = a, idx = i;
    mna[i] = {mn, idx};
  }
  mn = INF;
  for(int i = 1; i <= n; i++) {
    cin >> b;
    if(b < mn) mn = b, idx = i;
    mnb[i] = {mn, idx};
  }

  ll type, cost;
  for(int i = 1; i <= m; i++) {
    cin >> type >> cost;
    if(type == 1) type1[cnt1++] = {cost, i};
    else type2[cnt2++] = {cost, i};
  }
  sort(type1, type1+cnt1);
  sort(type2, type2+cnt2);
  ll res = bin();
  cout << res << "\n";
  if(res != -1) for(auto x : ans) cout << x.st << " " << x.nd << "\n";
  
}
