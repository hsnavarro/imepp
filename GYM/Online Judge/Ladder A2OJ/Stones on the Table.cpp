#include<bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main(){
    scanf("%d", &n);
    cin >> s;
    for(int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) ans++;
    }

    cout << ans << endl;

    return 0;
}