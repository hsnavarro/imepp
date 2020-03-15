#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
ll a, n, cmp[N];
set<ll> ans;
vector<ll> v;

void gen() {
    for(ll i = 2; i < N; i++) if (!cmp[i])
            for (ll j = i * i; j < N; j += i) cmp[j] = 1;

    for(ll i = 2; i < N; i++) if(!cmp[i]) ans.insert(i*i);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    gen();
    cin >> n;
    while(n--) cin >> a, v.pb(a);
    for(int i = 0; i < v.size(); i++){
        if(ans.count(v[i])) printf("YES\n");
        else printf("NO\n");
    }
}