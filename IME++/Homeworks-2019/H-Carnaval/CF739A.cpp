#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a, b, mn = INF;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--) cin >> a >> b, mn = min(mn, b - a + 1);
    cout << mn << endl;
    for(int i = 0; i < n; i++) cout << i%mn  << " ";
    cout << endl;
}
