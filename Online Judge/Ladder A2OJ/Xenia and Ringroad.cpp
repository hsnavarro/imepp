#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int n, m, a;
vector<int> v;
ll ans, cnt;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a;
        v.pb(a);
    }

    for(int i = 0; i + 1 < m; i++) if(v[i+1] < v[i]) cnt++;

    ans = (1ll*n*cnt + 1ll*v.back());
    cout << --ans << endl;
}