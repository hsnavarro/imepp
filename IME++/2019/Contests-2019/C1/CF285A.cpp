#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i = k + 1; i >= 1; i--) cout << i << " ";
    for(int i = k + 2; i <= n; i++) cout << i << " ";
}
