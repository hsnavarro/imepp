#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main(){
    cin >> s;
    while(s.size() != 1) {
        for (auto p : s) n += p - '0';
        s = to_string(n);
        n = 0, k++;
    }

    cout << k << endl;
}