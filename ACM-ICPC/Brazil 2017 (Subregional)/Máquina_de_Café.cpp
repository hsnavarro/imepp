//
// Created by Henrique Navarro on 09/09/2018.
//

//
// Created by Henrique Navarro on 09/09/2018.
//

#include <bits/stdc++.h>
using namespace std;

int a, b, c, a1, a2, a3, ans;

int main(){

 scanf("%d%d%d",&a,&b,&c);

 a1 = 2*b + 4*c;
 a2 = 2*a + 2*c;
 a3 = 2*b + 4*a;

 ans = min(a1, min(a2,a3));

 printf("%d\n", ans);

    return 0;
}