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

mint mpow(mint x, int n){
  if(n==1)return x;
  if(n==0)return 1;

  if(n%2==0){
    return mpow(x*x, n/2);
  }else{
    return mpow(x*x, n/2) * x;
  }
}

int main(){
  int n,k;
  cin >> n >> k;

  mint memo[100001];

  mint ans = 0;
  for(int i = k; i >=1; i--){
    mint t = (k/i);
    // mint s = 1;
    // REP(j,n)s*=t;
    mint s = mpow(t,n);

    FOR(j,2,k/i+1)s-=memo[i*j];
    memo[i] = s;
    ans += s * i;
  }

  // REP(i,k+1){
  //   cout << i << " " << memo[i].x << endl;
  // }

  cout << ans.x << endl;

}

