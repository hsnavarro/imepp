#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, aux, cnt, h, sum;
vector<pii> v;
//cont, num

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &aux);
        sum = 1;
        while(v.size() and v.back().nd <= aux){
            cnt = v.back().st, h = v.back().nd;
            if(h != aux and cnt & 1) { printf("NO\n"); return 0; } // n pode subir
            sum += cnt, v.pop_back(); // subindo e atualizando o topo da pilha
        }
        v.pb({sum, aux});
    }

    while(v.size() > 1){
        if(v.back().st & 1) { printf("NO\n"); return 0; } // num impar, n pode subir
        v.pop_back();
    }

    printf("YES\n");
}