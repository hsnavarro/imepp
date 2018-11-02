#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

int maj[] = {2, 2, 1, 2, 2, 2, 1};
string notas[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int aux, cond[12], a, res;
set<int> notes[12];

int main(){

    cl(cond,1);

    int n;

    for(int k = 0; k < 12; k++) {
        aux = k+1;
        notes[k].insert(aux);
        for (int i = 0; i < 12; i++) {
            aux += maj[i%7];
            notes[k].insert((aux-1)%12 + 1);
        }
    }

   // for(auto c : notes[1]) printf("%d ", c);

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        for(int k = 0; k < 12; k++) {
         if(!(notes[k].count((a-1)%12 + 1))) cond[k] = 0;
        }
    }

    res = 0;

    for(int k = 0; k < 12; k++){
        if(cond[k]) {
            cout << notas[k] << endl;
            res = 1;
            break;
        }
    }

    if(!res) printf("desafinado\n");


    return 0;
}

