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

const int N = 1e5 + 5;

int t, n, cond1, cond2;
int ad, ans;
string pros;
set<string> arm;

int lr (char a){
    int aux;
    if(a == 'd' or a == 'f') aux = 1;
    else aux = 2;
    return aux;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = 0;
        arm.clear();
        while(n--) {
            cin >> pros;
            ad = 2;
            cond1 = lr(pros[0]);

            for (int i = 1; i < pros.size(); i++) {
                cond2 = lr(pros[i]);
                if (cond1 == cond2) ad += 4;
                else ad += 2;
                cond1 = cond2;
            }
            if (arm.count(pros)) ad /= 2;
            arm.insert(pros);
            ans += ad;
        }
        printf("%d\n", ans);


    }

    return 0;
}