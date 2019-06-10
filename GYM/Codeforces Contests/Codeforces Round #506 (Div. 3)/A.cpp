//
// Created by Henrique Navarro on 08/09/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

int lps[100];
string p;

void preKMP(){
    lps[0] = 0;
    int j = 0;
    int m = p.size();
    for (int i=1; i < m; i++) {
        while (j > 0 and p[j] != p[i]) j = lps[j-1];
        if (p[j] == p[i]) j++;
        lps[i] = j;
    }
}


int main(){
    int n, k;
    string res;
    string c;
    string d;

    scanf("%d %d", &n, &k);

    cin >> p;

    preKMP();
    c = p.substr(0, n-lps[n-1]);
    d = p.substr(n-lps[n-1], n);

    while(k--){
        res += c;
    }
    res += d;



    cout << res << endl;


    return 0;
}