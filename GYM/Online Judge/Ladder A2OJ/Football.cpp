#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

map<string, int> mp;
string s, r;
int n, mx = -1;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { cin >> s; mp[s]++; }
    for(auto x : mp) if(x.second > mx) { mx = x.second; r = x.first; }

    cout << r << endl;

    return 0;
}