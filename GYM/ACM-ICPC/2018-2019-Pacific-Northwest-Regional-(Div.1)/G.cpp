#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef long double type;
typedef long double ld;

const ld EPS = -1e9;

struct point {
  type x, y;

  point(type x = 0, type y = 0) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(type k) { return point(k*x, k*y); }
  point operator /(type k) { return point(x/k, y/k); }

  type operator *(point p) { return x*p.x + y*p.y; }
  type operator %(point p) { return x*p.y - y*p.x; }
  type operator !() {return (*this)*(*this); };
};

point projectPointSegment(point p, point a, point b) {
  ld r = (b-a)*(b-a);
  if(abs(r) < EPS) return a;
  r = ((p-a)*(b-a))/r;
  if(r < 0) return a;
  if(r > 1) return b;
  return a + (b-a)*r;
}

ld dist(point p, point a, point b) {
  return sqrt(!(projectPointSegment(p, a, b) - p));
}

ld x, y, xa, ya, xb, yb;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> x >> y >> xa >> ya >> xb >> yb;
  point ori = point(x, y);
  point a = point(max(xa, xb), max(ya, yb));
  point b = point(min(xa, xb), max(ya, yb));
  point c = point(min(xa, xb), min(ya, yb));
  point d = point(max(xa, xb), min(ya, yb));

  cout << fixed << setprecision(3);
  cout << min({dist(ori, a, b), dist(ori, b, c), dist(ori, c, d), dist(ori, d, a)}) << "\n";
}
