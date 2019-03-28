// String Hashing - O(n + m)
const int MOD = 1e9+9;
char s[N];
int n; // n = strlen(s)
ll sum[N], p[N+1] = {1, 313};

void build(char* s){
  sum[0] = s[0];
  for(int i = 1; i < n; i++) sum[i] = (sum[i-1]*p[1]+s[i])%MOD;
  for(int i = 2; i <= N; i++) p[i] = p[1]*p[i-1]%MOD;
}

int fhash(int l = 0, int r = n-1){
  return p[N]*(((sum[r] - sum[l-1]*p[r-l+1]%MOD)+MOD)%MOD)%MOD;
}

int hashsimple(char* s, int l = 0, int r = n-1, ll ans = 0){
  for(int i = l; i <= r; i++) ans = (ans + p[r-i]*s[i]%MOD)%MOD;
  return p[N]*ans%MOD;
}
