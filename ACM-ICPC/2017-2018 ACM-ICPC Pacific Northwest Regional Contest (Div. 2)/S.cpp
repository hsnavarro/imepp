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

int i1 = 0, i2 = 0, jst, j2, cont1 = -INF, cont2 = -INF, r1, r2, b1, b2, i, j;
string a;

int main(){
    cin >> a;
    for(int k = 0; k < a.size(); k++){
        if(a[k] == 'B') b1++, b2++;
        else r1++, r2++;

        if(r2 - b2 < 0) r2 = 0, b2 = 0, i2 = k + 1;
        if(r2 - b2 > cont2) cont2 = r2 - b2, j2 = k;

        if(b1 - r1 < 0) r1 = 0, b1 = 0, i1 = k + 1;
        if(b1 - r1 > cont1) cont1 = b1 - r1, jst = k;
    }

    if(cont1 == cont2){
        if(i1 < i2) i = i1, j = jst;
        if(i2 < i1) i = i2, j = j2;
        if(i1 == i2){
            if(jst < j2) i = i1, j = jst;
            if(j2 <= jst) i = i2, j = j2;
        }
    }
    if(cont1 > cont2) i = i1, j = jst;
    if(cont1 < cont2) i = i2, j = j2;

    printf("%d %d\n", i + 1, j + 1);

    return 0;
}