#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define nd second
#define st first

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

ll s, n, m, l, esc, idx, v;
ll a[N];

int main(){
    scanf("%lld %lld %lld", &n, &m, &l);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

    for(int i = 0; i < n; i++){
        int cont = 0;
        while(a[i] > l){
            if(a[i] > l and !cont) {s++; cont++;}
            i++;
        }
    }

    for(int i = 0; i < m; i++){
        scanf("%lld", &esc);
        if(!esc) printf("%lld\n", s);
        else{
            scanf("%lld%lld", &idx, &v);
            idx--;
            if(a[idx] > l) continue;
            a[idx] += v;
            if(a[idx] > l){
                if(idx == 0){
                    if(a[idx+1] <= l) s++;
                }
                else if(idx == n - 1){
                    if(a[idx-1] <= l) s++;
                }
                if(idx != 0 and idx != n-1){
                    if(a[idx-1] <= l and a[idx+1] <= l) s++;
                    if(a[idx-1] > l and a[idx+1] > l) s--;
                }
            }
        }
    }


    return 0;
}