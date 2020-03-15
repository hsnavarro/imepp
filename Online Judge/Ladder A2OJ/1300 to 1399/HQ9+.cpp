#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

char s[N];

int main() {
    fgets(s, N, stdin);
    int m = strlen(s);

    for(int i = 0; i < m - 1; i++){
        if(s[i] == 'H' or s[i] == 'Q' or s[i] == '9') {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}