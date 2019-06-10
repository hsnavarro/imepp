//
// Created by Henrique Navarro on 30/08/2018.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

string t, p;
char pat[N];
int lps[N], cont, m, n;

void preKMP(string& p){
    lps[0] = 0;
    int j = 0;
    for (int i=1; i < m; i++) {
        while (j > 0 and p[j] != p[i]) j = lps[j-1];
        if (p[j] == p[i]) j++;
        lps[i] = j;
    }
}

int KMP(string& t, string& p) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 and p[j] != t[i]) j = lps[j-1];
        if (p[j] == t[i]) j++;
    }
    return j;
}

int main(){
    int aux;

    while(scanf("%s", pat) != EOF) {
        p = pat;
        reverse(p.begin(), p.end());
        t = p;
        reverse(p.begin(), p.end());

        m = p.size();
        n = t.size();

        preKMP(t);
        aux = KMP(p, t);

        for (int i = 1; i <= m - aux; i++) {
            p.push_back(p[m - aux - i]);
        }

        cout << p << endl;
    }

    return 0;

}
