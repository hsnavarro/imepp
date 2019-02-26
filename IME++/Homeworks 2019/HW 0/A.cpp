#include <bits/stdc++.h>
using namespace std;

int n, m, sum;

bool ok(int &i){
    string aux = to_string(i);
    set<char> cnt;
    for(auto p : aux) cnt.insert(p);
    return cnt.size() == aux.size();
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> n >> m){
        sum = 0;
        for(int i = n; i <= m; i++) sum += ok(i);
        cout << sum << endl;
    }
}