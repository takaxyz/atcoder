#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

void solve() {
  int n; string s;
  cin >> n >> s;
  int l = (n+1)/2;
  vector<mint> pw(l);
  pw[0] = 1;
  rep(i,l-1) pw[i+1] = pw[i]*26;
  mint ans;
  rep(i,l) {
    int x = s[i]-'A';
    ans += pw[l-i-1]*x;
  }
  string t = s.substr(0,n-l);
  reverse(t.begin(),t.end());
  t = s.substr(0,l)+t;
  if (t <= s) ans += 1;
  cout << ans.val() << endl;
}

int main() {
  int T;
  cin >> T;
  rep(ti,T) solve();
  return 0;
}
