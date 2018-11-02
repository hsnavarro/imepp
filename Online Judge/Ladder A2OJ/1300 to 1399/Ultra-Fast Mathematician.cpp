#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

char v1[N],v2[N],v3[N];

int main() {
    fgets(v1, N, stdin);
    fgets(v2, N, stdin);
    int m = strlen(v2);
    for(int i = 0; i < m-1; i++){
        if(v1[i] == v2[i]) v3[i] = '0';
        else v3[i] = '1';
    }

    for(int i = 0; i < m - 1; i++){
        printf("%c", v3[i]);
    }


    return 0;
}