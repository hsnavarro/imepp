#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 2;
const int MIN_M = 0;

const int MAX_N = 20;
int MAX_M = 20;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(MIN_N, MAX_N);
    MAX_M = min(MAX_M, (n*(n-1))/2);
    int m = rnd.next(MIN_M, MAX_M);

    vector<pair<int, int> > edgs;
    set<pair<int, int> > pairs;
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        if(i != j and !pairs.count({i, j}) and !pairs.count({j, i})) edgs.push_back({i, j}), pairs.insert({i, j});
      }
    }

    shuffle(edgs.begin(), edgs.end());

    cout << n << " " << m << endl;

    for(int i=0; i < m; i++) cout << edgs[i].first << " " << edgs[i].second << endl;
}
