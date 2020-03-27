#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;

double n, x, k, a, b, c;


double func(double x){
    return (n*(n-1)/4) - ((x-1)*(2*n - x)/2);
}


int main(){
    scanf("%lf", &n);

    a = 0.5;
    b = -1*(2+4*n)/4;
    c = (n*n + 3*n)/4;
    //db(a _ b _ c);

    x = (-1ll*b - 1ll*(sqrt(b*b - 4*a*c)))/(2*a);
    ll aux = floor(x);
    if(func(aux) <= 0) aux--;
    //db(func(aux));

    printf("%ld\n", aux);

    return 0;
}