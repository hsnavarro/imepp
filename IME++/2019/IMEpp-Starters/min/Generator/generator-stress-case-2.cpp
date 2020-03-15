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
    int q = rnd.next(MIN_Q, MAX_Q);
    cout << q << endl;
    for(int i=0; i<q; i++){
    	int n = rnd.next(MIN_N-1, MAX_N-1);
    	int m = rnd.next(MAX_N, MAX_N);
    	cout << n << " " << m << endl;
		}
}

