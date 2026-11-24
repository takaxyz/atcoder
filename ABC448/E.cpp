#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
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

using mint = modint1000000007;

ll mpow(ll x, ll n, ll mod){
  ll y=1;
  while(n){
    if(n & 1)y = (y * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return y % mod;
}

int main(){
  int k,m;
  cin >> k >> m;
  vi c(k),l(k);
  REP(i,k)cin >> c[k-1-i] >> l[k-1-i]; 
  
  ll mod = m * 10007;

  vector<ll> d(32);
  d[0]=10;
  FOR(i,1,32)d[i] = d[i-1]*d[i-1] % mod;

  vector<ll> rep(32);
  rep[0]=1;
  FOR(i,1,32)rep[i] = (rep[i-1]*d[i-1] + rep[i-1])% mod;

  ll dgt=0;
  ll res=0;
  REP(i,k){
    ll cc = c[i] * mpow(10,dgt,mod);

    ll now=0;
    REP(j,32){
      if((l[i]>>j) & 1ll){
        now = (now * d[j] + rep[j]) % mod;
      }
    }
    res += cc * now;
    res %= mod;
    dgt+=l[i];
  }
  cout << res/m << endl;
}

