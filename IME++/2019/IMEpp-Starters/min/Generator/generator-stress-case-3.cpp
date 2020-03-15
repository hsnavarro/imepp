#include "testlib.h"
#include <iostream>

using namespace std;

const int MAX_Q = 1e5;
const int MAX_N = 1e6;
const int MIN_Q = 1e5;
const int MIN_N = 1e6;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int q = MAX_Q;
    cout << q << endl;
    int n = MAX_N - 1;
    int m = MAX_N;
    for(int i=0; i<q; i++){
    	cout << n << " " << m << endl;
      n--, m--;
		}
}

