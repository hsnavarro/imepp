#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int n, f[200];
string s, ans;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for(auto x : s) f[x]++;

    for(int i = 0; i < 200; i++) {
        if(f[i] % n) { cout << -1 << endl; return 0; }
        int aux = f[i]/n;
        while(aux--) ans.pb(char(i));
    }

    while (n--) cout << ans;

}