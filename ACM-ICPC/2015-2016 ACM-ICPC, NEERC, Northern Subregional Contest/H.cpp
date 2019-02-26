#include <bits/stdc++.h>
using namespace std;

int n;
string a = "ab";
string b = "bC";

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("hash.in");
    ofstream cout("hash.out");
    cin >> n;
    for(int i = 0; i < n; i++){
        string aux;
        for(int j = 0; j < 31; j++){
            if(i & (1 << j)) aux += a;
            else aux += b;
        }
        cout << aux << endl;
    }
}