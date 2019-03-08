#include<bits/stdc++.h>
using namespace std;

int n, neg, pos, aux;
vector<int> a, b, c, in;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &aux);
        in.push_back(aux);
    }

    for(auto x : in) {
        if(x < 0) neg++;
        if(x > 0) pos++;
    }

    if(pos){
        for(auto x : in) {
            if (x > 0 and !b.size()) { b.push_back(x); continue; }
            if (x < 0 and !a.size()) { a.push_back(x); continue; }
            c.push_back(x);
        }
    }

    if(!pos) {
        for (auto x : in) {
            if (x < 0 and b.size() != 2) { b.push_back(x); continue; }
            if (x < 0 and !a.size()) { a.push_back(x); continue; }
            c.push_back(x);
        }
    }

    printf("%d ", a.size());
    for(auto x : a) printf("%d ", x);
    printf("\n");

    printf("%d ", b.size());
    for(auto x : b) printf("%d ", x);
    printf("\n");

    printf("%d ", c.size());
    for(auto x : c) printf("%d ", x);
    printf("\n");

