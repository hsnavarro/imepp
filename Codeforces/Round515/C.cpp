#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

int q, idx,ans, aux, l, r;
char ch;
map<int, int> ids;

int main(){
    scanf("%d", &q);
    l = 0; r = 1;

    while(q--){
        scanf(" %c %d", &ch, &idx);

        if(ch == 'L') ids[idx] = l--;
        if(ch == 'R') ids[idx] = r++;

        if(ch == '?'){
            aux = ids[idx];
            ans = min(r - aux, aux - l) - 1;

            printf("%d\n", ans);
        }

    }

    return 0;
}