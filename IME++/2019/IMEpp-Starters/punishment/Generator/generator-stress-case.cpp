#include <bits/stdc++.h>
#include "testlib.h"
 
const int MAX_SIZE = 8e6;
const int ROOT = 4e3;

using namespace std;
 
vector<string> string_queries;
vector<int> values, chosen;
 
int main(int argc, char * argv[]){
  registerGen(argc, argv, 1);
 
  int x = atoi(argv[1]);
  int cnt = 0;
  for(int i = 0; i < MAX_SIZE; i += x) cnt++;
  cout << min(MAX_SIZE, cnt) << endl;
  string gen = rnd.next("[a-z]{%d}", int(MAX_SIZE));
  cnt = 0;
  for(int i = 0; i < gen.size(); i += x) {
    cnt++;
    cout << gen.substr(i, x) << "\n";
    if(cnt == MAX_SIZE) break;
  }
  return 0;
}
