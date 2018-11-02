#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int sum, n, par, imp, aux;

int main() {
    scanf("%d\n", &n);
    while(n--){
        scanf("%d", &aux);
        if(aux & 1) imp++;
        else par++;
        sum += aux;
    }
    if(sum & 1) cout << imp << endl;
    else cout << par << endl;

    return 0;
}