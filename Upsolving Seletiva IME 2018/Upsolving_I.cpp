//
// Created by Henrique Navarro on 08/08/2018.
//

#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

typedef long long ll;

struct Point{
    ll x, y;
    Point(ll x, ll y){this->x=x, this->y=y;}

    Point operator+(Point p){
        return Point(x + p.x, y + p.y);
    }
    Point operator-(Point p){
        return Point(x - p.x, y - p.y);
    }
    ll operator%(Point p){
        return x*p.y - y*p.x;
    }
};

bool inside_convex_poly(vector<Point>& v, Point p){
    for(int i = 0; i+1< v.size(); i++){
        if((v[i+1] - v[i]) % (p - v[i]) < 0) return false;
    }
    if((v[0] - v[v.size()-1]) % (p - v[v.size()-1]) < 0) return false;
    return true;
}

int main(){

    int s, r, m, n;
    ll aux1, aux2;
    vector<Point> S, R, M, N;

    scanf("%d %d %d", &s, &r, &m);

    for(int i=0;i<s;i++){
        scanf("%lld %lld", &aux1, &aux2);
        S.push_back(Point(aux1,aux2));
    }

    for(int i=0;i<r;i++){
        scanf("%lld %lld", &aux1, &aux2);
        R.push_back(Point(aux1,aux2));
    }

    for(int i=0;i<m;i++){
        scanf("%lld %lld", &aux1, &aux2);
        M.push_back(Point(aux1,aux2));
    }

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%lld %lld", &aux1, &aux2);
        N.push_back(Point(aux1,aux2));
    }

    for(int i=0;i<n;i++) {
       if(inside_convex_poly(S, N[i])) {printf("Sheena\n"); continue;}
       if(inside_convex_poly(R, N[i])) {printf("Rose\n"); continue;}
       if(inside_convex_poly(M, N[i])) {printf("Maria\n"); continue;}
           printf("Outside\n");
    }


    return 0;
}