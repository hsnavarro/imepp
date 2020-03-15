#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back

const int N = 5e5 + 5;

int n, p = -1, u = -1, ps = -1, us = -1;
string s, res;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++) if(s[i] == '[') { p = i; break; }
    for(int i = s.size() - 1; i >= 0; i--) if(s[i] == ']') { u = i; break; }

    for(int i = max(0, p); i <= max(0, u); i++) if(s[i] == ':') { ps = i; break; }
    for(int i = max(0, u); i >= max(0, p); i--) if(s[i] == ':') { us = i; break; }

    res.pb('['), res.pb(':');
    for(int i = ps + 1; i < us; i++) if(s[i] == '|') res.pb(s[i]);
    res.pb(':'), res.pb(']');

    if(p != -1 and u != -1 and ps != -1 and us != -1 and ps != us) cout << res.size() << endl;
    else cout << -1 << endl;
}