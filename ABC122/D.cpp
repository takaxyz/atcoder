#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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


mint mpow(int x, int n){
  if(n==0)return 1;

  mint y = mpow(x, n/2);
  y *= y;

  if(n%2==1) y *=x;
  return y;
}

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} c(200005);



mint dp[101][4][4][4];

int main(){
  int n;
  cin >> n;

  // A:0 C:1 G:2 T:3
  // AGC: 021
  // NG AGC(021), ACG(012), GAC(201), A?GC(0?21), AG?C(02?1)

  REP(i,4)REP(j,4)REP(k,4){
    if(i==0 && j==2 && k==1)continue;
    if(i==2 && j==0 && k==1)continue;
    if(i==0 && j==1 && k==2)continue;
    dp[3][i][j][k]=1;
  }

  FOR(i,4,n+1){
    REP(c1,4)REP(c2,4)REP(c3,4)REP(c4,4){
      if(c2==0 && c3==2 && c4==1)continue;
      if(c2==0 && c3==1 && c4==2)continue;
      if(c2==2 && c3==0 && c4==1)continue;
      if(c1==0 && c3==2 && c4==1)continue;
      if(c1==0 && c2==2 && c4==1)continue;
      dp[i][c2][c3][c4] += dp[i-1][c1][c2][c3];
    }
  }

  mint ans=0;
  REP(i,4)REP(j,4)REP(k,4)ans+=dp[n][i][j][k];

  cout << ans.x << endl;
}

