#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

string s, c, d, a, b, m;

int main(){
    cin >> s >> c;
    string z = to_string(stoi(c) + stoi(s));

    for(int i = 0; i < s.size(); i++) if(s[i] != '0') a.push_back(s[i]);
    for(int i = 0; i < c.size(); i++) if(c[i] != '0') b.push_back(c[i]);
    for(int i = 0; i < z.size(); i++) if(z[i] != '0') m.push_back(z[i]);

    if(stoi(a) + stoi(b) == stoi(m)) printf("YES\n");
    else printf("NO\n");

    return 0;
}