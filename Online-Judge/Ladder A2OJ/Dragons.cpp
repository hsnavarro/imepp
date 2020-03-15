#include<bits/stdc++.h>
using namespace std;

int s, n, a, b, cnt;
vector<pair<int, int>> ans;

int main(){
    scanf("%d%d", &s, &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        ans.push_back({a, b});
    }

    sort(ans.begin(), ans.end());

    for(auto x : ans){
        if(x.first < s) s += x.second, cnt++;
        else break;
    }

    printf("%s\n", cnt == n ? "YES" : "NO");

    return 0;
}