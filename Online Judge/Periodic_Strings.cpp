//
// Created by Henrique Navarro on 29/08/2018.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 80 + 5;

char p[N];
int lps[N], m;

void preKMP(char* p){
    lps[0] = 0;
    int j = 0;
    for (int i=1; i < m; i++) {
        while (j > 0 and p[j] != p[i]) j = lps[j-1];
        if (p[j] == p[i]) j++;
        lps[i] = j;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", p);
        m = strlen(p);
        preKMP(p);

        if (!(m % (m - lps[m - 1]))) printf("%d\n", m - lps[m - 1]);
        else printf("%d\n", m);

        if (i != n) printf("\n");
    }
    return 0;
}
