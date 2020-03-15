#include <bits/stdc++.h>
#include "testlib.h"
 
const int MAX_SIZE = 8e6;

using namespace std;
 
vector<string> string_queries;
vector<int> values, chosen;
 
int main(int argc, char * argv[]){
  registerGen(argc, argv, 1);
 
  int n = atoi(argv[1]);
  cout << n << endl;

  for (int i = 1; i <= MAX_SIZE; i++) values.push_back(i);
  shuffle(values.begin(), values.end());
  for(int i = 0; i < n; i++) chosen.push_back(values[i]);
  sort(chosen.begin(), chosen.end());
  string generatedWord = rnd.next("[a-z]{%d}", int(MAX_SIZE));
  int x = 0;
  for(int i = 0; i < chosen.size(); i++){
    cout << generatedWord.substr(x, chosen[i] - x) << "\n";
    x = chosen[i];
  }
  //cout << generatedWord.substr(x, generatedWord.size() - x) << "\n";
 
  return 0;
}
