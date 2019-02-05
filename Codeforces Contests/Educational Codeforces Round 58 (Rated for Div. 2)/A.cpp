#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, l, r, d, res;

bool out(int x){
    if(x < l or x > r) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n--){
        cin >> l >> r >> d;
        int a = (1 + d - 1)/d * d;
        int b = (r + d)/d * d;
        if(out(a) and out(b)) res = min(a, b);
        else if(!out(a) and out(b)) res = b;
        else res = a;

        cout << res << endl;
    }


}