#include <bits/stdc++.h>
using namespace std;

int q;
int a, b;
long long n;

int main(){
    cin >> q;
    while(q--){
        cin >> n >> a >> b;
        if(a <= b) cout << 1ll*n*a << endl;
        else cout << 1ll*((n/2)*b + 1ll*a) << endl;
    }
    return 0;
}