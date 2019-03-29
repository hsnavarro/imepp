#include <bits/stdc++.h>
using namespace std;

set<string> st;
string s;
int cnt;
string nam[] = {"Danil", "Olya", "Slava", "Ann", "Nikita" };

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);

  for(int i = 0; i < 5; i++) st.insert(nam[i]);
  
  cin >> s;
  for(int j = 3; j <= 6; j++)
    for(int i = 0; i + j <= s.size(); i++) if(st.count(s.substr(i, j))) cnt++;
  
  cout << (cnt == 1 ? "YES" : "NO") << endl;
}
