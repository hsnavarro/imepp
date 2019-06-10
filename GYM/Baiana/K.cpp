#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, gols1, gols2;
string a, jog1, jog2;
map<string, piii> info;
vector<string> times;

// pts, vitorias, gols

bool cmp(string a, string b){
  if(info[a].st == info[b].st and info[a].nd.st == info[b].nd.st and 
      info[a].nd.nd == info[b].nd.nd) return a < b;
  if(info[a].st == info[b].st and info[a].nd.st == info[b].nd.st) return info[a].nd.nd > info[b].nd.nd;
  if(info[a].st == info[b].st) return info[a].nd.st > info[b].nd.st;
  return info[a].st > info[b].st;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  for(int i = 0; i < 4; i++) cin >> a, times.push_back(a);
  cin >> n;
  while(n--){
    cin >> jog1 >> gols1 >> jog2 >> gols2;
    info[jog1].nd.nd += gols1-gols2;
    info[jog2].nd.nd += gols2-gols1;
    if(gols1 == gols2) info[jog1].st++, info[jog2].st++;
    else {
      string ganha;
      if(gols1 > gols2) ganha = jog1;
      else ganha = jog2;
      info[ganha].st += 3;
      info[ganha].nd.st++;
    }
  }
  sort(times.begin(), times.end(), cmp);
  cout << times[0] << endl;
  cout << times[1] << endl;
}
