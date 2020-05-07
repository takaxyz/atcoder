#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

int main(){
  string s;
  cin >> s;

  vector<vector<mint>> dp(s.size()+1, vector<mint>(4,0));

  dp[0][0]=1;

  REP(i,s.size()){
    switch(s[i]){
      case 'A':
        // 選ばない
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][1];
        dp[i+1][2] += dp[i][2];
        dp[i+1][3] += dp[i][3];
        // 選ぶ
        dp[i+1][1] += dp[i][0];
        break;
      case 'B':
        // 選ばない
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][1];
        dp[i+1][2] += dp[i][2];
        dp[i+1][3] += dp[i][3];
        // 選ぶ
        dp[i+1][2] += dp[i][1];
        break;
      case 'C':
        // 選ばない
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][1];
        dp[i+1][2] += dp[i][2];
        dp[i+1][3] += dp[i][3];
        // 選ぶ
        dp[i+1][3] += dp[i][2];
        break;
      case '?':
        // 選ばない(A,B,Cの3文字どれでも可なので3倍する)
        dp[i+1][0] += dp[i][0] * 3;
        dp[i+1][1] += dp[i][1] * 3;
        dp[i+1][2] += dp[i][2] * 3;
        dp[i+1][3] += dp[i][3] * 3;
        // 選ぶ(Aで1文字目を選ぶ、Bで2文字目を選ぶ、Cで3文字目を選ぶ)
        dp[i+1][1] += dp[i][0];
        dp[i+1][2] += dp[i][1];
        dp[i+1][3] += dp[i][2];
        break;
    }

  }

  cout << dp[s.size()][3].x << endl;
}

