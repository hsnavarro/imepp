#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n;
ld x, y, r, need;
vector< pair<ld, pair<ld, ld>> > pts;
vector<ld> dists;
ld xc, yc, rc;
priority_queue<pair<ld, int>> pq;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> xc >> yc;
  for(int i = 0; i < n; i++){
    cin >> x >> y >> r;
    pts.push_back({r, {x, y}});
  }

  for(int i = 0; i < pts.size(); i++){
    ld xax = pts[i].second.first;
    ld yax = pts[i].second.second;
    ld rax = pts[i].first;

    ld dist = sqrt((xc - xax)*(xc - xax) + (yc - yax)*(yc - yax)) - rax;
    dists.push_back(dist);
    //cerr << "dist: " << dist << endl;
    pq.push({-dist, i});
  }

  while(pq.size()){
    int id = pq.top().second;
    ld dist = dists[id];
    pq.pop();
    if(dist > rc) need += dist - rc, rc += dist - rc;
    rc += pts[id].first; 
  }

  cout << fixed << setprecision(10) << need << endl;
}
