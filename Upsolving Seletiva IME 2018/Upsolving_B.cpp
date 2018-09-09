//
// Created by Henrique Navarro on 08/08/2018.
//
#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

string a, d;

int main(){

    cin >> a;

    for(int i = 0; i < a.size(); i++) {
        if (a[i] == 'C') {
            d.push_back('B');
        }
        if (a[i] == 'S') {
            d.push_back('D');
        }
    }


    if(d.size()>2) {
        for (int i = 0; i + 2 < d.size(); i++) {
            if (d[i] == 'B' and d[i + 1] == 'B' and d[i + 2] == 'B') {
                d[i + 2] = 'P';
            }
            if (d[i] == 'D' and d[i + 1] == 'D' and d[i + 2] == 'D') {
                d[i + 2] = 'T';
            }
        }
    }

    cout << d << endl;

    return 0;
}
