#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> a;

int main(){
  // ios_base::sync_with_stdio(0), cin.tie(0);
  while(~scanf("%d", &n)){
    a.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    long double ans = 0.0;
    sort(a.begin(), a.end());
    vector<int> left, right;
    for(int i = 0; i < a.size(); i++) (i & 1) ? left.pb(a[i]) : right.pb(a[i]);
    a.clear();
    
    //cerr << "inicio" << endl;
    //for(auto x : left) cerr << x << endl;
    //for(auto x : right) cerr << x << endl;
    //cerr << "fim" << endl;

    for(auto x : right) a.pb(x);
    reverse(left.begin(), left.end());
    for(auto x : left) a.pb(x);
    for(int i = 0; i+1 < a.size(); i++) ans += a[i]*a[i+1];
    ans += a[0]*a[a.size() - 1];
    ans = ans*sin(2*acos(-1.)/n)/2;
    printf("%.3Lf\n", ans);
  }
}
