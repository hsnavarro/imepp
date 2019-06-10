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

ll l, r, l0, r0, ans;
vector<ll> luck;

void gen(){
    luck.pb(0);
    string ans;
    for(int i = 1; i <= 10; i++)
        for(int j = 0; j < (1 << i); j++) {
            for (int k = 0; k < i; k++) ans = ((1 << k) & j ? '7' : '4') + ans;
            luck.pb(stoll(ans)), ans.clear();
        }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    gen();

    cin >> l >> r;

    for(int i = 1; i < luck.size(); i++){
        l0 = max(l, luck[i - 1] + 1);
        r0 = min(r, luck[i]);
        if(l0 <= r0) ans += luck[i]*(r0 - l0 + 1);
    }

    cout << ans << endl;
}