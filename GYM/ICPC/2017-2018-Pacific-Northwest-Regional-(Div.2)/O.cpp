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

int col[50][50], lin[50][50], table[50][50], n;
int aux, ok;
string a;

bool check(){
    for(int i = 1; i + 1 <= n; i++) {
        if(table[1][i] + 1 != table[1][i + 1]) return false;
        if(table[i][1] + 1 != table[i + 1][1]) return false;
    }
    return true;
}

int main(){

    while( scanf("%d", &n) != EOF) {
        cl(col, 0);
        cl(lin, 0);
        cl(table, 0);
        ok = 0;


        for (int i = 1; i <= n; i++) {
            cin >> a;
            for (int j = 1; j <= n; j++) {
                aux = a[j - 1];

                if (aux >= 65) aux -= 55;
                else aux -= 48;

                if (lin[i][aux] == 1 or col[j][aux] == 1) ok = 1;

                table[i][j] = aux;
                col[j][aux] = 1;
                lin[i][aux] = 1;
            }
        }

        if (ok) printf("No\n");
        else printf("%s\n", check() ? "Reduced" : "Not Reduced");
    }

    return 0;
}