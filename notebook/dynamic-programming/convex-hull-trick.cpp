// Convex Hull Trick

typedef long long type;
struct line { type b, m; };

int nh, pos;
line hull[N];

bool check(line s, line t, line u){
  //attention for overflow
  return ld (u.b - t.b)/(t.m - u.m) > ld (t.b - s.b)/(s.m - t.m);
}

void update(line s){
  if(nh == 1 and hull[nh-1].b == s.b) nh--;
  if(nh > 0 and s.m >= hull[nh-1].m) return;
  while(nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) nh--;
  pos = min(pos, nh);
  hull[nh++] = s;
}

type eval(int id, type x) { return hull[id].b + hull[id].m*x; }

// Linear Query
// queries always move to the right
/*
type query(type x){
  while(pos+1 < nh and eval(pos, x) > eval(pos+1, x)) pos++;
  return eval(pos, x);
}
*/

type query(type x){
  int l = 0, r = nh-1, mid;
  while(r - l > 5){
    mid = (l+r)/2;
    if(eval(mid+1, x) < eval(mid, x)) l = mid;
    else r = mid+1;
  }
  type mn = LINF;
  for(int i = l; i <= r; i++) mn = min(mn, eval(i, x)); 
  return mn;
}
