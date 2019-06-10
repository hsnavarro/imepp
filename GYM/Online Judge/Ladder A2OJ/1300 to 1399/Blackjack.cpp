#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n;

int main() {
    scanf("%d", &n);
    n -= 10;
    if(n >= 2 and n <= 9){
        printf("4\n");
        return 0;
    }
    if(n == 1 or n == 11){
        printf("4\n");
        return 0;
    }
    if(n == 10){
        printf("15\n");
        return 0;
    }
    else printf("0\n");

    return 0;
}