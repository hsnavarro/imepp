//
// Created by Henrique Navarro on 27/07/2018.
//

#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " <<
using namespace std;

const int N = 1e5+5;
const int M = 2*1e9+7;


struct Point{
        int x, y;
        Point(int x, int y){this->x=x, this->y=y;} //:x(x),y(y)}}
        Point operator+(Point p){
            return Point(x + p.x, y + p.y);
        }
        Point operator-(Point p){
            return Point(x - p.x, y - p.y);
        }
        double operator%(Point p){
            return x*p.y - y*p.x;
        }
        double operator*(Point p){
            return x*p.x + y*p.y;
        }
        double operator!(){
            return hypot(x,y);
        }
        Point operator*(double k){
            return Point(k*x, k*y);
        }
};

int main(){

    int x_o[2], y_o[2], x_f[2], y_f[2];

    for(int i = 0; i < 2; i++) {
        scanf("%d %d %d %d", &x_o[i], &y_o[i], &x_f[i], &y_f[i]);
    }

    Point A_o = Point(x_o[0],y_o[0]);
    Point A_f = Point(x_f[0],y_f[0]);
    Point B_o = Point(x_o[1],y_o[1]);
    Point B_f = Point(x_f[1],y_f[1]);

    Point V1 = A_f - A_o;
    Point V2 = B_f - B_o;
    Point S = V1 + V2;
    //db(S.x _ S.y);

    printf("%.9lf %.9lf\n", !V1, !V2);
    printf("%.9lf %.9lf\n", float(S.x), float(S.y));
    printf("%.9lf %.9lf\n", V1*V2, V1%V2);
    printf("%.9lf\n", abs(V1%V2)/2);




    return 0;
}


