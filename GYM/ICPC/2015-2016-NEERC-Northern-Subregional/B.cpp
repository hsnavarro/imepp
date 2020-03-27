#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

const int N = 1e5;

int b, w, i;
char t[N][4];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("black.in");
    ofstream cout("black.out");
    cin >> b >> w;
    i = 0;
    if(abs(b - w) > 1){
        if(b > w) {
            for (int j = 0; j < 4; j++) t[0][j] = '.';
            w--;
            i = 1;
            while(abs(b - w) > 1){
                t[i][0] = t[i][3] = '.';
                if(i & 1) t[i][2] = '.', t[i][1] = '@';
                else t[i][2] = '@', t[i][1] = '.';
                i++, b--;
            }
            for (int j = 0; j < 4; j++) t[i][j] = '.';
            i++;
        }else{
            for (int j = 0; j < 4; j++) t[0][j] = '@';
            b--;
            i = 1;
            while(abs(b - w) > 1){
                t[i][0] = t[i][3] = '@';
                if(i & 1) t[i][2] = '@', t[i][1] = '.';
                else t[i][2] = '.', t[i][1] = '@';
                i++, w--;
            }
            for (int j = 0; j < 4; j++) t[i][j] = '@';
            i++;
        }
    }

    while(b > 0 or w > 0){
        if(b > w){
            if(b > 0) {
                for (int j = 0; j < 4; j++) t[i][j] = '@';
                b--, i++;
            }
            if(w > 0) {
                for (int j = 0; j < 4; j++) t[i][j] = '.';
                w--, i++;
            }
        }
        else{
            if(w > 0) {
                for (int j = 0; j < 4; j++) t[i][j] = '.';
                w--, i++;
            }
            if(b > 0) {
                for (int j = 0; j < 4; j++) t[i][j] = '@';
                b--, i++;
            }
        }
    }

    cout << i << " " << 4 << endl;
    for(int k = 0; k < i; k++){
        for(int p = 0; p < 4; p++){
            cout << t[k][p];
        }
        cout << "\n";
    }
}