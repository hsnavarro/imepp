#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int aux, x, y;

int main() {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf(" %d", &aux);
            if(aux) {
                x = i+1;
                y = j+1;
            }
        }
    }

    printf("%d\n", abs(x-3) + abs(y-3));

    return 0;
}