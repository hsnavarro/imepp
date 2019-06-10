#include <bits/stdc++.h>
using namespace std;

int inp, venc, quin, quad;
int quant, m;
vector<int> win;
map<int, int> bet;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  for(int i = 0; i < 6; i++) cin >> inp, win.push_back(inp);
  cin >> m;
  while(m--){
    bet.clear();
    cin >> quant;
    int cnt = 0;
    for(int i = 0; i < quant; i++) cin >> inp, bet[inp]++;
    for(auto x : win) if(bet[x]) cnt++;
    if(cnt == 6) venc++;
    else if(cnt == 5) quin++;
    else if(cnt == 4) quad++;
  }
  cout << venc << " " << quin << " " << quad << endl;
}
