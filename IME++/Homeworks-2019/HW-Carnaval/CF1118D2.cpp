#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

ll n, m;
vector<ll> v;

bool test(ll k){
    ll sum = 0;
    for(int i = 0; i < n; i++) sum += max(0ll, v[i] - i/k);
    return sum >= m;
}

int bin(int l, int r){
    int mid;
    while(l != r){
        mid = (l+r)/2;
        if(test(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    int x = bin(1, 2e5+1);
    cout << (x == 2e5+1 ? -1 : x) << endl;
}
