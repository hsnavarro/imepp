#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n;

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n*n/2;){
        for(int j = 0; j < n/2; j++){
            printf("%d %d%s", i, n*n+1-i, j == n/2-1 ? "\n" : " ");
            i++;
        }
    }

    return 0;
}