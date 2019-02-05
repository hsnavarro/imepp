#include<bits/stdc++.h>
using namespace std;

int n, cond;
string s, ans;

int main(){
    scanf("%d", &n);
    cin >> s;
    for(int i = 0; i+1 < n; i++)
        if(s[i] != s[i+1]){
            ans.push_back(s[i]);
            ans.push_back(s[i+1]);
            break;
        }

    if(ans.size()){
        printf("YES\n");
        cout << ans << endl;
    }
    else printf("NO\n");


    return 0;
}