#include <bits/stdc++.h>
using namespace std;

int n, v, i = 1, cap, res;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> v;
    while(i + cap < n){
        while(cap < min(v, n - i)) cap++, res += i;
        i++, cap--;
    }
    cout << res << endl;
}