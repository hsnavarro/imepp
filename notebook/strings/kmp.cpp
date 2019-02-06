// KMP - O(n + m)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char t[N], p[N];
int lps[N], cont, m, n;

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
            cont++;
            j = lps[j];
        }
    }
}

int main(){

    cin >> t;
    cin >> p;

    m = strlen(p);
    n = strlen(t);

    preKMP(p);
    KMP(p, t);

   printf("%d\n", cont);

    return 0;

}
