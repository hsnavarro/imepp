#include<bits/stdc++.h>
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5000 + 5;
int n, freq[4], res;
string s;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    res = n/3;
    cin >> s;
    for(auto x : s) freq[x - 48]++;

    if(freq[2] < res) {
        for(int i = s.size() - 1; i >= 0; i--) {
            if(freq[2] == res or freq[1] == res) break;
            if (s[i] == '1' and freq[1] > res) s[i] = '2', freq[2]++, freq[1]--;
        }

        for(int i = s.size() - 1; i >= 0; i--) {
            if(freq[2] == res or freq[0] == res) break;
            if (s[i] == '0' and freq[0] > res) s[i] = '2', freq[2]++, freq[0]--;
        }
    }

    if(freq[0] < res){
        for(int i = 0; i < s.size(); i++) {
            if(freq[2] == res or freq[0] == res) break;
            if (s[i] == '2' and freq[2] > res) s[i] = '0', freq[2]--, freq[0]++;
        }

        for(int i = 0; i < s.size(); i++) {
            if(freq[1] == res or freq[0] == res) break;
            if (s[i] == '1' and freq[1] > res) s[i] = '0', freq[0]++, freq[1]--;
        }
    }

    if(freq[1] < res){
        for(int i = 0; i < s.size(); i++) {
            if(freq[2] == res or freq[1] == res) break;
            if (s[i] == '2' and freq[2] > res) s[i] = '1', freq[2]--, freq[1]++;
        }

        for(int i = s.size() - 1; i >= 0; i--) {
            if(freq[1] == res or freq[0] == res) break;
            if (s[i] == '0' and freq[0] > res) s[i] = '1', freq[1]++, freq[0]--;
        }
    }


    cout << s << endl;
}