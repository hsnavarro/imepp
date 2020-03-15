#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, aux, cont, k, t, sum;
vector<ll> s;

int main(){
    scanf("%lld %lld", &n, &t);
    for(int i = 0; i < n; i++){
        scanf("%lld", &aux);
        s.push_back(aux);
    }

    while(t) {
        aux = 0;
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + s[i] <= t) {
                sum += s[i];
                aux++;
            }
        }
        if(!sum) break;
        cont += t/sum * aux;
        t -= t/sum * sum;
    }

    printf("%lld\n", cont);

    return 0;
}