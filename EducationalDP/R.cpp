#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

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
};

vector<vector<mint>> mtxmul(vector<vector<mint>> &x, vector<vector<mint>>& y){
  int s = x.size();
  int t = x[0].size();
  int u = y[0].size();
  vector<vector<mint>> res(s, vector<mint>(u, 0));

  REP(i,s)REP(j,u)REP(k,t){
    res[i][j] +=  x[i][k] * y[k][j];
  }

  return res;
}

vector<vector<mint>> mtxpow(vector<vector<mint>> &x, ll n){
  vector<vector<mint>> res(x.size(), vector<mint>(x.size()));

  if(n==0){
    REP(i,x.size()){
      res[i][i]=1;
    }
    return res;
  }

  res = mtxpow(x, n/2);
  res = mtxmul(res, res);
  if(n & 1){
    res = mtxmul(res, x);
  }
  return res;
}



int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<mint>> a(n, vector<mint>(n));
  REP(i,n)REP(j,n){
    int _a;
    cin >> _a;
    a[i][j] = _a;
  }

  vector<vector<mint>> ak = mtxpow(a, k);

  mint ans=0;
  REP(i,n)REP(j,n)ans += ak[i][j];

  cout << ans.x << endl;

}

