#include <bits/stdc++.h>
using namespace std;

int n, cont, cic, pass = 1e9, pen, ul = 1e9;
string esc, aux;

int main(){
    scanf("%d", &n);
    while(n-- and ++cic) {
        printf("%d 1\n", cont);

        cin >> aux;
        fflush(stdout);

        if(cic == 1) esc = aux;
        pass /= 2;

        if (esc == aux) {
            pen = cont;
            cont += pass;
        }
        else {
            ul = cont;
            cont -= pass;
        }
    }
    printf("%d 0 %d 2", pen, ul);
    return 0;
}