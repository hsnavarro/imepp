#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

int t, n, x, y, sum, val;
vector<pair<int, int>> v, in;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        in.clear(), v.clear(), sum = 0, val = 0;
        while(n--){
            cin >> x >> y;
            in.pb({x, y});
            v.pb({x, -1}), v.pb({y, 1});
        }
        sort(v.begin(), v.end());
        for(auto x : v) {
            sum -= x.nd;
            if(!sum and x != v.back()) { val = x.st; break; }
        }

        if(!val) cout << -1;
        else for(auto p : in) cout << (p.nd <= val ? 1 : 2) << " ";
        cout << endl;
    }
}