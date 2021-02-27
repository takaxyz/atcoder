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

const int mod = 1000000000;
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

// 1-indexed
template <typename T>
struct BIT{
private:
  int n;
  vector<T> d;

public:
  BIT(int _n=0){
    n = _n;
    d = vector<T>(n+1);
  }

  void add(int i, T x){
    for(i++; i <= n; i+=i&-i)d[i]+=x;
  }
  // [1,i] 
  T sum(int i){
    T x = 0;
    for(i++; i > 0; i-=i&-i)x+=d[i];
    return x;
  }
  // [i,j] 
  T sum(int i, int j){
    return sum(j) - sum(i-1);
  }
};


int main(){
  int k;
  cin >> k;
  vvi s(k, vi(21,0));
  vector<mint> inv(k);
  REP(i,k){
    int n;
    cin >> n;
    vi a(21,0);
    BIT<mint> bitt(21);
    mint tmp=0;
    REP(j,n){
      int x;
      cin >> x;
      s[i][x]++;
      tmp += bitt.sum(x+1,20);
      bitt.add(x,1);
    }
    inv[i] = tmp;
  }

  // REP(i,k){
  //   cout << inv[i].x << endl;
  // }

  int q;
  cin >> q;

  BIT<mint> bit(21);

  vi ss(21,0);
  mint ans=0;
  REP(i,q){
    int b;
    cin >> b;
    b--;
    FOR(j,1,21){
      ans += bit.sum(j+1,20) * s[b][j];
    }
    FOR(j,1,21){
      bit.add(j, s[b][j]);
    }
    ans += inv[b];
  }

  cout << ans.x << endl;
}

