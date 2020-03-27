#include <bits/stdc++.h>
using namespace std;

int n, cur, atual, freq[15][15], podeJogar;
string s;

int nxt(int x){ return x+1 > n ? 1 : x+1; }

int num(char a){
  if(a == 'A') return 1;
  if(a == 'D') return 10;
  if(a == 'Q') return 11;
  if(a == 'J') return 12;
  if(a == 'K') return 13;
  return a - '0';
}

int check_win(){
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= 13; j++) if(freq[i][j] == 4 and i != cur) return i;
  return 0;
}

void stop(){ if(check_win()) cout << check_win() << "\n", exit(0); }

int card(){
  int mn = 20, id;
  for(int j = 1; j <= 13; j++) 
    if(freq[atual][j] and freq[atual][j] < mn) mn = freq[atual][j], id = j;
  return id;
}

void pass(){ 
  int id = card();
  freq[atual][id]--, freq[nxt(atual)][id]++; 
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> cur;
  for(int i = 1; i <= n; i++){
    cin >> s;
    for(auto x : s) freq[i][num(x)]++;
  }

  stop(), atual = cur;
  while(1){
    if(atual == cur){
      if(podeJogar) podeJogar = 0, cur = nxt(cur);
      else podeJogar = 1, pass();
    } else pass();
    stop(), atual = nxt(atual);
  }
}
