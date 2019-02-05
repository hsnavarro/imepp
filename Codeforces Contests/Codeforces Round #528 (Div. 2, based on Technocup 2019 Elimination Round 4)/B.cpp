#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back

typedef long long ll;

const int N = 5e5 + 5;
const int A = 26;

int n, k, c, p;

int main(){
    cin >> n >> k;
    for(int i = k - 1; i > 0; i--) if(n%i == 0) {
            p = i;
            c = n/p;
            break;
        }

    cout << c*k + p << endl;
}