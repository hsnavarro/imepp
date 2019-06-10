//
// Created by Henrique Navarro on 30/08/2018.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

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
    int n, period, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        scanf("%s", p);
        preKMP(p);

        printf("Test case #%d\n", i);

        for(int j = 1; j <= m; j++) {
            if (!(j % (j - lps[j - 1]))) period = j - lps[j - 1];
            else period = j;
            k = j/period;
            if(k > 1) printf("%d %d\n", j, k);

        }

        if (i != n) printf("\n");
    }
    return 0;
}
