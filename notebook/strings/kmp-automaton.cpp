// KMP Automaton - O(n + m)
// Fast Matching, Slow Build

// max size pattern
const int N = 1e5 + 5;

int cnt, lps[N], nxt[N][26];

void prekmp(string &p) { 
  for(int i = 1, j = 0; i < p.size(); i++) {
    while(j and p[j] != p[i]) j = lps[j-1];
    if(p[j] == p[i]) j++;
    lps[i] = j;
  }

  for(int i = 0; i < p.size(); i++) {
    for(int c = 0; c < 26; c++) {
      int aux = i;
      while(aux and p[aux] - 'a' != c) aux = lps[aux-1];
      if(p[aux] - 'a' == c) aux++;
      nxt[i][c] = aux;
    }
  }
}

void kmp(string &s, string &p) {
  for(int i = 0, j = 0; i < s.size(); i++) {
    j = nxt[j][s[i] - 'a'];
    if(j == p.size()) {
      //match i-j+1
      cnt++;
      j = lps[j-1];
    }
  }
}
