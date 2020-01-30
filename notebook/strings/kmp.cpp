// KMP - O(n + m)

// max size pattern
const int N = 1e5 + 5;

int lps[N], cont;

void preKMP(string &p){
    lps[0] = 0;
    int j = 0;
    for (int i = 1, m = p.size(); i < m; i++) {
        while (j > 0 and p[j] != p[i]) j = lps[j-1];
        if (p[j] == p[i]) j++;
        lps[i] = j;
    }
}

void KMP(string &p, string &t) {
   int j = 0;
    for (int i = 0, n = p.size(), m = t.size(); i < n; i++) {
        while (j > 0 and p[j] != t[i]) j = lps[j-1];
        if (p[j] == t[i]) j++;
        if (j == m) {
            // match i-j+1
            cont++;
            j = lps[j-1];
        }
    }
}
