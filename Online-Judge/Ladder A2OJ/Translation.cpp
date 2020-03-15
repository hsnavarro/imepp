#include<bits/stdc++.h>
using namespace std;

string s, t;

int main(){
    cin >> s >> t;
    reverse(s.begin(), s.end());
    printf("%s\n", s == t ? "YES" : "NO");

    return 0;
}