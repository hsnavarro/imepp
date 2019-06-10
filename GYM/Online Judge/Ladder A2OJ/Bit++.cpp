#include<bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main(){
    scanf("%d", &n);
    while(n--) {
        cin >> s;
        if(s[1] == '+') ans++;
        if(s[1] == '-') ans--;
    }
    cout << ans << endl;

    return 0;
}