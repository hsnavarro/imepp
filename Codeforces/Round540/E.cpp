#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    if(1ll*k*(k-1) < 1ll*n) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 2; i <= k; i++){
            for(int j = 1; j < i; j++){
                cout << j << " " << i << endl;
                n--;
                if(n == 0) return 0;
                cout << i << " " << j << endl;
                n--;
                if(n == 0) return 0;
            }
        }
    }
}