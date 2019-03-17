#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, string> mp;

int n, t, a, b;
char s[25];
string aux;

int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%d%d%s", &a, &b, s);
    aux = s;
    mp[make_pair(a, b)] = aux;
  }
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &a, &b);
    strcpy(s, mp[make_pair(a, b)].c_str());
    printf("%s\n", s);

  }
}
