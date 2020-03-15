#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int x, y, x_A, y_A, x_C, y_C;

int main() {
    scanf("%d %d", &x, &y);
    x_C = y_A = abs(x) + abs(y);
    if(x < 0) x_C = -x_C;
    if(y < 0) y_A = -y_A;
    if(x_A >= x_C) {swap(x_A, x_C); swap(y_A, y_C);}
    printf("%d %d %d %d\n",x_A, y_A, x_C, y_C);

    return 0;
}