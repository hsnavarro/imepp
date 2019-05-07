#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int x, y;

struct point{
  int x, y;
  point () : x(0), y(0) {}
  point (int x, int y) : x(x), y(y) {}
  int operator * (point b){ return x*b.x + y*b.y; }
  point operator + (point b){ return {x + b.x, y + b.y}; } 
  point operator - (point b){ return {x - b.x, y - b.y}; }
};

int area(point a, point b){ return a.x*b.y-a.y*b.x; }

bool isRight(point a, point b, point c){
  if((c-b)*(a-b) == 0 and area(c-b, a-b)) return true;
  if((b-c)*(a-c) == 0 and area(b-c, a-c)) return true;
  if((b-a)*(c-a) == 0 and area(b-a, c-a)) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  point a[3];
  for(int i = 0; i < 3; i++) cin >> x >> y, a[i] = {x, y};
  if(isRight(a[0], a[1], a[2])) return cout << "RIGHT" << endl, 0;

  for(int i = 0; i < 5; i++){
    point aux(dx[i], dy[i]);
    for(int j = 0; j < 3; j++) if(isRight(a[j] + aux, a[(j+1)%3], a[(j+2)%3]))
      return cout << "ALMOST" << endl, 0; 
  }
  cout << "NEITHER" << endl;
}
