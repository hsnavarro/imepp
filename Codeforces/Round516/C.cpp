#include <bits/stdc++.h>
#define cl(x, v) memset((x), (v), sizeof(x))
using namespace std;

string s;
int n;

string ans (string s) {
    int freq[26];
    cl(freq, 0);

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a'] += 1;
    }

    string ans = "";

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i]; j++) {
            ans += (char)(97 + i);
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    cin >> s;

    cout << ans(s);

    return 0;
}
