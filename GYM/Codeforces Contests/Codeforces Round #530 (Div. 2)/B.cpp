#include <bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

ll n;
ll func(ll n){
    if(n&1) return func(n-1) + (n+1)/2;
    return (n/2+1)*(n/2);
}

ll bin(ll l, ll r){
    ll mid;
    while(l < r){
        mid = (l+r+1)/2;
        if(func(mid) < n) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ll a = bin(0, 1e5);
    cout << a + 2 << endl;

}