#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
const int m = 2019;
 
int main() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  int x = 1, tot = 0;
  vector<int> cnt(m);
  ll ans = 0;
  rep(i,n) {
    cnt[tot]++;
    tot += (s[i]-'0')*x;
    tot %= m;
    ans += cnt[tot];
    cout << i << " " << tot << " " << cnt[tot] << endl;
    x = x*10%m;
  }
  cout << ans << endl;
  return 0;
}

