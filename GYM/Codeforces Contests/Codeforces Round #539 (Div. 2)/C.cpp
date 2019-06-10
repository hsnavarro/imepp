#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, res, s;
vector<int> v;
map<int, int> mp1, mp2;

//s[l-1] = s[r]

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int a;
    while(n--) cin >> a, v.push_back(a);
    mp2[0]++;
    for(int i = 0; i < v.size(); i++){
        s ^= v[i];
        if((i+1)&1){
            res += mp1[s];
            mp1[s]++;
        }else{
            res += mp2[s];
            mp2[s]++;
        }
    }
    cout << res << endl;
}