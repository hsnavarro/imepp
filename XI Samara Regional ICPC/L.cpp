#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int A = 200;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int m[A][N], n, idx;
string s, p, esc;
char aux;
stack<int> pilha;

int main(){
  cin >> s;
  cl(m, 63);
  for(int i = s.size(); i >= 1; i--){
    for(int j = 'a'; j <= 'z'; j++){
      m[j][i-1] = m[j][i];
      m[s[i-1]][i-1] = i;
    }
  }
  scanf("%d", &n);
  while(n--){
   cin >> esc;
   if(esc == "push"){
      scanf(" %c", &aux);
        pilha.push(m[aux][idx]);
        idx = m[aux][idx];
   }
   else{
      pilha.pop();
      if(pilha.empty()) idx = 0;
      else idx = pilha.top();
   }
   printf("%s\n", idx == INF ? "NO" : "YES");
  }
  return 0;
}
