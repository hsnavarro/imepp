#include<bits/stdc++.h>
using namespace std;

int n, m, aux, s, k;
vector<int> v;


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        v.push_back(aux);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(i == m) break;
        if(v[i] >= 0) break;
        s += abs(v[i]);
    }

    printf("%d\n", s);


    return 0;
}