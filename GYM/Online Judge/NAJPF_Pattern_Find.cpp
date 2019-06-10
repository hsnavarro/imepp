//
// Created by Henrique Navarro on 29/08/2018.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char t[N], p[N];
int lps[N], cont, m, n;
vector<int> idx;

void preKMP(char* p){
    lps[0] = 0;
    int j = 0;
    for (int i=1; i < m; i++) {
        while (j > 0 and p[j] != p[i]) j = lps[j-1];
        if (p[j] == p[i]) j++;
        lps[i] = j;
    }
}

void KMP(char* p, char* t) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 and p[j] != t[i]) j = lps[j-1];
        if (p[j] == t[i]) j++;
        if (j == m) {
           idx.push_back(i-j+2);
            cont++;
            j = lps[j];
        }
    }
}

int main(){

    int test;

    scanf("%d", &test);

    for(int i = 1; i <= test; i++){
        idx.clear();
        cont = 0;

        cin >> t;
        cin >> p;

        m = strlen(p);
        n = strlen(t);

        preKMP(p);
        KMP(p, t);

        if(idx.size()) {
            printf("%d\n", cont);
            for(int  j= 0; j < idx.size(); j++) {
                if (j != idx.size() - 1) printf("%d ", idx[j]);
                else printf("%d\n", idx[j]);
            }
        }
        else{
            printf("Not Found\n");
        }
        if(i != test) printf("\n");
    }
    return 0;

}


