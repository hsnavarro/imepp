//
// Created by Henrique Navarro on 30/08/2018.
//
#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e6 + 5;

string s, p;
char pat[N];
int b[N], n, m; // n = strlen(s), m = strlen(p);

void kmppre(string p) {
    b[0] = -1;
    for (int i = 0, j = -1; i < m; b[++i] = ++j)
        while (j >= 0 and p[i] != p[j])
            j = b[j];
}

int kmp(string s, string p) {
    int j = 0;
    for (int i = 0; i < n;) {
        while (j >= 0 and s[i] != p[j]) j=b[j];
        i++, j++;
    }
    return j;
}

int main(){
    int aux;
    string a;

    while(scanf("%s", pat) != EOF) {
        p = pat;
        reverse(p.begin(), p.end());
        s = p;
        reverse(p.begin(), p.end());

        m = n = p.size();

        kmppre(s);
        aux = kmp(p, s);
       // db(aux);
        //db(m - aux);

        a = p.substr(0, m - aux);
       // if()
        //cout << a << endl;
        reverse(a.begin(), a.end());

        p += a;

        cout << p << endl;
    }

    return 0;

}
