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

int di[4] ={-1,1,0,0};
int dj[4] ={0,0,1,-1};


int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];
  int cnt=0;
  REP(i,h)REP(j,w)if(s[i][j]=='.')cnt++;
  vvi a(h,vi(w,0));
  vvi b(h,vi(w,0));

  REP(i,h){
    int c=0;
    REP(j,w){
      if(s[i][j]=='.'){
        c++;
      }else{
        REP(k,c){
          a[i][j-1-k] = c;
        }
        c=0;
      }
    }
    REP(k,c){
      a[i][w-1-k] = c;
    }
  }
  REP(i,w){
    int c=0;
    REP(j,h){
      if(s[j][i]=='.'){
        c++;
      }else{
        REP(k,c){
          b[j-1-k][i] = c;
        }
        c=0;
      }
    }
    REP(k,c){
      b[h-1-k][i] = c;
    }
  }

  // REP(i,h)REP(j,w){
  //   cout << a[i][j] << (j==w-1 ? "\n" : " ");
  // }
  // REP(i,h)REP(j,w){
  //   cout << b[i][j] << (j==w-1 ? "\n" : " ");
  // }

  mint all=mpow(2,cnt);
//  cout << all.x << endl;

  mint ans=0;
  REP(i,h)REP(j,w){
    if(s[i][j]=='#')continue;
    // int c=1;
    // REP(k,4){
    //   int ni = i;
    //   int nj = j;
    //   while(true){
    //     ni += di[k];
    //     nj += dj[k];
    //     if(ni < 0 || ni >= h || nj < 0 ||nj >= w)break;
    //     if(s[ni][nj]=='#')break;
    //     c++;
    //   }
    // }
//    cout << c << endl;
    int c = a[i][j] + b[i][j] - 1;
    ans += (mpow(2,c)-1) * mpow(2,cnt-c);
//    cout << ((mpow(2,c)-1) * mpow(2,cnt-c)).x << endl;
  }
  cout << ans.x << endl;

}

