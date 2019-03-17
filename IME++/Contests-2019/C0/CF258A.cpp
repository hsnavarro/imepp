#include <bits/stdc++.h>
using namespace std;

string a;

int main(){
  cin >> a;
  for(int i = 0; i < a.size(); i++){
    if(a[i] == '0'){
      cout << a.substr(0, i) + a.substr(i+1, a.size()) << endl;
      return 0;
    }
  }

  cout << a.substr(0, a.size()-1) << endl;
}
