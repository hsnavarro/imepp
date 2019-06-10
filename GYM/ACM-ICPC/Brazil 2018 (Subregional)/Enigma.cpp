#include <bits/stdc++.h>
using namespace std;

string txt, pat;
int cond, cont;

int main(){
    cin >> txt >> pat;

    for(int i = 0; i <= txt.size() - pat.size(); i++){
        cond = 1;
        for (int j = 0; j < pat.size(); j++) {
            if(txt[i+j] == pat[j]) {cond = 0; break;}
        }
        if(cond) cont++;
    }

    printf("%d\n", cont);

    return 0;
}