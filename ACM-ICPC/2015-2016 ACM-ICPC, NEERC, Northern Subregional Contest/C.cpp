#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 130;

int freq[N][2], s;
string s1, s2;

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("concatenation.in");
    ofstream cout("concatenation.out");
    cin >> s1 >> s2;
    for(int i = 1; i < s1.size(); i++) freq[s1[i]][0]++;
    for(int i = 0; i < s2.size()-1; i++) freq[s2[i]][1]++;
    for(int i = 0; i < N; i++) s += freq[i][0]*freq[i][1];
    cout << 1ll*s1.size()*s2.size() - s << endl;
}