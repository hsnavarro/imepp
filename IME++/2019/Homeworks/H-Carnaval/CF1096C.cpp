#include <bits/stdc++.h>
using namespace std;

int p, t;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> p;
        int mdc = __gcd(180, p);
        int n = 180 / mdc;
        if (p/mdc <= n - 2) cout << n << endl;
        else cout << 2 * n << endl;
    }
}
