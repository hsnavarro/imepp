#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l, r, l0, r0, ans;
vector<ll> luck;

void gen(){
    luck.push_back(0);
    string ans;
    for(int i = 1; i <= 10; i++)
        for(int j = 0; j < (1 << i); j++) {
            for (int k = 0; k < i; k++) ans = ((1 << k) & j ? '7' : '4') + ans;
            luck.push_back(stoll(ans)), ans.clear();
        }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    gen();
    cin >> l >> r;
    int i = 1;
    while(i < luck.size()){  
        l0 = max(l, luck[i - 1] + 1);
        r0 = min(r, luck[i]);
        if(l0 > r0) break;
        ans += luck[i]*(r0 - l0 + 1);
        i++;
    }
    cout << ans << endl;
}
