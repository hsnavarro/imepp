#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll comb(ll k) { return k*(k-1)/2; }
ll n, m, k1, k2;

int main(){
    cin >> n >> m;
    k2 = comb(n - m + 1);
    k1 = (m - n + n/m * m) * comb(n/m) + (n - n/m * m) * comb(n/m + 1);
    cout << k1 << " " << k2 << endl;
}