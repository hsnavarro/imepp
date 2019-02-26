#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

#define pb push_back

typedef long long ll;

ll n, mx, d, raz, query = 60;
vector<ll> v;

ll bin_search(ll l = 0, ll r = 1e9){
    ll mid, aux;
    while(l != r){
        mid = (l+r)/2;
        cout << "> " << mid << endl;
        query--;
        cin >> aux;
        if(aux) l = mid + 1;
        else r = mid;
    }
    return l;
}

ll findD (){
    vector<ll> in;
    ll aux;
    in.pb(mx);
    int i = 0;
    while(query and i < v.size()){
        cout << "? " << v[i] << endl;
        cin >> aux;
        if(aux != mx) in.pb(aux);
        i++, query--;
    }
    sort(in.begin(), in.end());
    ll d = 0;
    for(ll i = 0; i + 1 < in.size(); i++) d = __gcd(d, in[i+1] - in[i]);
    return d;
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    random_device rd;
    mt19937 g(rd());
    cin >> n;
    mx = bin_search();
    for(ll i = 1; i <= n; i++) v.pb(i);
    shuffle(v.begin(), v.end(), g);
    raz = findD();
    cout << "! " << mx + (1-n)*raz << " " << raz << endl;
}