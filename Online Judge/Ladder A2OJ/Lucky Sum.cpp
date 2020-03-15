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

ll l, r, n = 4, l0, r0, ans;
vector<ll> luck;

ll next(ll a){
    string s = to_string(a);
    string ans;
    int k = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '4') {
            k = i;
            for (int i = 0; i < s.size(); i++) {
                if (i < k) ans.pb(s[i]);
                if (i == k) ans.pb('7');
                if (i > k) ans.pb('4');
            }
            return stoll(ans);
        }
    }

    for(int i = 0; i <= s.size(); i++) ans.pb('4');
    return stoll(ans);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    luck.pb(0);
    while(n <= 1e10) luck.pb(n), n = next(n);

    cin >> l >> r;

    for(int i = 1; i < luck.size(); i++){
        l0 = max(l, luck[i - 1] + 1);
        r0 = min(r, luck[i]);
        if(l0 <= r0) ans += luck[i]*(r0 - l0 + 1);
    }

    cout << ans << endl;
}