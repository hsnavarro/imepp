#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, SQ = 320;

long long n, c1, c2, c3, r1, r2, r3, cond = 0, aux;

int main() {

   scanf("%lld", &n);

   for(long long i = 3; i <= 5; i++){
       aux = (n - i);
       if(aux%3 == 0){
           aux = aux/3;
           cond = 1;
       }

       if(cond) {
           if (i == 3) {
               r1 = 1;
               r2 = 1;
               r3 = 3 * aux + 1;
           }
           if (i == 4) {
               r1 = 1;
               r2 = 1;
               r3 = 3 * aux + 2;
           }
           if (i == 5) {
               r1 = 1;
               r2 = 2;
               r3 = 3 * aux + 2;
           }
           break;
       }
   }

   printf("%lld %lld %lld\n", r1, r2, r3);


    return 0;
}
