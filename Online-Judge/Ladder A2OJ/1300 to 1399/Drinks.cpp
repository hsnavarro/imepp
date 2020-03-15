#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

double n, sum, aux;

int main() {
    scanf("%lf", &n);

    for(int i = 0; i < n; i++){
        cin >> aux;
        sum += aux;
    }
    printf("%.12lf\n", sum/n);


    return 0;
}