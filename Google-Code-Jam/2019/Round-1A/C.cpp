#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

string s;
int n, t, trie[50*N][30], isEnd[50*N], cnt, func[50*N], test;
void add (string s){
  int u = 0;
  for(int i = 0; i < s.size(); i++){
    int a = s[i] - 'A';
    if(!trie[u][a]) trie[u][a] = ++cnt;
    u = trie[u][a];
    if(i == s.size() - 1) isEnd[u] = 1;
  }
}

bool isLeaf(int x){
  for(int i = 0; i < 30; i++) if(trie[x][i]) return false;
  return true;
}

int go(){
  for(int i = 0; i <= cnt; i++) if(isLeaf(i)) func[i] = 1;

  for(int i = cnt; i >= 0; i--){
    int sum = 0;
    if(!isLeaf(i) and isEnd[i]) sum++;
    for(int j = 0; j < 30; j++) if(trie[i][j]) sum += func[trie[i][j]];
    if(sum >= 2 and i) sum -= 2;
    func[i] += sum;
  }

  return n - func[0];
}

void reset(){
  memset(trie, 0, sizeof trie);
  memset(isEnd, 0, sizeof isEnd);
  cnt = 0;
  memset(func, 0, sizeof func);
}

int main(){
  cin >> t;
  while(t-- and ++test){
    reset();
    cin >> n;
    for(int i = 0; i < n; i++) 
      cin >> s, reverse(s.begin(), s.end()),  add(s);
    cout << "Case #" << test << ": " << go() << endl;
  }
}
